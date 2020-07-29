#pragma once
#include <map>

struct atlasColor{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

const std::map<unsigned char, atlasColor> atlasColors = {
	{0, atlasColor{0, 0, 0}},
	{1, atlasColor{255, 0, 0}},
	{2, atlasColor{0, 255, 0}},
	{3, atlasColor{0, 0, 255}},
	{4, atlasColor{28, 28, 28}},
	{6, atlasColor{117, 96, 70}},
	{7, atlasColor{0, 255, 255}},
	{8, atlasColor{0, 107, 0}},
	{11, atlasColor{255, 136, 0}},
	{12, atlasColor{255, 255, 186}},
	{13, atlasColor{255, 123, 225}},
	{14, atlasColor{123, 0, 224}},
	{16, atlasColor{123, 0, 168}},
	{17, atlasColor{224, 224, 224}},
	{18, atlasColor{186, 212, 255}},
	{19, atlasColor{255, 237, 178}},
	{20, atlasColor{173, 101, 43}},
	{21, atlasColor{254, 254, 254}},
	{22, atlasColor{255, 255, 0}},
	{23, atlasColor{231, 28, 217}},
	{24, atlasColor{148, 50, 28}},
	{25, atlasColor{255, 154, 0}},
	{26, atlasColor{70, 59, 43}},
	{27, atlasColor{50, 50, 107}},
	{28, atlasColor{186, 186, 89}},
	{29, atlasColor{89, 89, 89}}
};

