#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "atlascolor.h"
#include "im/include/im.h"
#include "im/include/im_image.h"
#include "im/include/im_process.h"
#include "im/include/im_convert.h"
#include "im/include/im_dib.h"

static void imImageViewFitRect(int cnv_width, int cnv_height, int img_width, int img_height, int* w, int* h)
{
	double rView, rImage;
	int correct = 0;

	*w = cnv_width;
	*h = cnv_height;

	rView = ((double)cnv_height) / cnv_width;
	rImage = ((double)img_height) / img_width;

	if ((rView <= 1 && rImage <= 1) || (rView >= 1 && rImage >= 1)) /* view and image are horizontal rectangles */
	{
		if (rView > rImage)
			correct = 2;
		else
			correct = 1;
	}
	else if (rView < 1 && rImage > 1) /* view is a horizontal rectangle and image is a vertical rectangle */
		correct = 1;
	else if (rView > 1 && rImage < 1) /* view is a vertical rectangle and image is a horizontal rectangle */
		correct = 2;

	if (correct == 1)
		*w = (int)(cnv_height / rImage);
	else if (correct == 2)
		*h = (int)(cnv_width * rImage);
}


HBITMAP CreateThumbnail(const char* filename, UINT thumb_size, BOOL& has_alpha)
{
	std::basic_ifstream<unsigned char> file(filename, std::ios::binary | std::ios::ate);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg); // Reset cursor
	std::vector<unsigned char> buffer(size);
	if (!file.read(buffer.data(), size)) {
		file.close();
		return NULL;
	}
	file.close();

	// Figure out image size, ignoring the header
	int image_size = static_cast<int>(sqrt(size - 20));

	// Invalid image
	if (image_size != 1024 && image_size != 512 && image_size != 256 && image_size != 128 && image_size != 64) {
		return NULL;
	}

	imImage* image = imImageCreate(image_size, image_size, IM_RGB, IM_BYTE);
	if (!image) {
		return NULL;
	}

	int count = image_size * image_size;
	unsigned char* idata = (unsigned char*)image->data[0];
	unsigned char* data = &buffer.data()[20];

	for (int i = 0; i < count; i++)
	{
		const auto val = atlasColors.find(data[i]);
		if (val != atlasColors.end() && data[i] != 0) {
			idata[i] = val->second.r;
			idata[i + (count)] = val->second.g;
			idata[i + (count * 2)] = val->second.b;
		//	idata[i + (count * 3)] = 255;
		}
		else {
			idata[i] = 34;
			idata[i + (count)] = 34;
			idata[i + (count * 2)] = 34;
			idata[i + (count * 3)] = 0;
		}
	}

	int thumb_width, thumb_height;
	imProcessFlip(image, image);

	imImageViewFitRect(thumb_size, thumb_size, image->width, image->height, &thumb_width, &thumb_height);

	imImage* thumb_image = imImageCreateBased(image, thumb_width, thumb_height, -1, -1);
	if (!thumb_image) {
		return NULL;
	}

	imProcessResize(image, thumb_image, 1);
	imImageDestroy(image);

	HBITMAP hbmp;
	HDC hDC = GetDC(NULL);

	imDib* dib = imDibSectionFromImage(hDC, &hbmp, thumb_image);
	if (!dib) {
		return NULL;
	}
	ReleaseDC(NULL, hDC);

	if (image->has_alpha)
		has_alpha = TRUE;
	else
		has_alpha = FALSE;

	imDibDestroy(dib);
	imImageDestroy(thumb_image);

	return hbmp;
}
