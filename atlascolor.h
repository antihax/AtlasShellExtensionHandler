#pragma once
#include <map>

struct atlasColor{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

const std::map<unsigned char, atlasColor> atlasColors = {

	{1, atlasColor{255, 0, 0}},
	{2, atlasColor{0, 255, 0}},
	{3, atlasColor{0, 0, 255}},
	{4, atlasColor{2, 2, 2}},
	{6, atlasColor{46, 30, 15}},
	{7, atlasColor{1, 255, 255}},
	{11, atlasColor{255, 63, 0}},
	{12, atlasColor{255, 255, 127}},
	{13, atlasColor{255, 51, 194}},
	{14, atlasColor{123, 0, 224}},
	{16, atlasColor{83, 0, 115}},
	{17, atlasColor{191, 191, 191}},
	{18, atlasColor{122, 170, 255}},
	{19, atlasColor{255, 216, 115}},
	{20, atlasColor{108, 33, 5}},
	{21, atlasColor{253, 253, 253}},
	{22, atlasColor{255, 255, 0}},
	{23, atlasColor{255, 0, 255}},
	{24, atlasColor{132, 31, 39}},
	{25, atlasColor{254, 166, 32}},
	{26, atlasColor{43, 39, 34}},
	{27, atlasColor{0, 0, 128}},
	{28, atlasColor{128, 128, 0}},
	{29, atlasColor{119, 136, 153}},
	{30, atlasColor{210, 50, 62}},
	{31, atlasColor{59, 48, 46}},
	{32, atlasColor{67, 27, 47}},
	{33, atlasColor{31, 23, 47}},
	{34, atlasColor{12, 50, 69}},
	{35, atlasColor{141, 37, 50}},
	{36, atlasColor{0, 120, 172}},
	{37, atlasColor{70, 134, 88}},
	{38, atlasColor{161, 214, 95}},
	{39, atlasColor{200, 72, 149}},
	{40, atlasColor{255, 211, 9}},
	{41, atlasColor{120, 36, 250}},
	{42, atlasColor{24, 173, 165}},
	{43, atlasColor{178, 212, 163}},
	{44, atlasColor{218, 119, 24}},
	{45, atlasColor{94, 100, 98}},
	{46, atlasColor{163, 149, 129}},
	{47, atlasColor{241, 154, 35}},
	{48, atlasColor{31, 86, 112}},
	{49, atlasColor{79, 70, 65}},
	{50, atlasColor{95, 28, 51}},
	{51, atlasColor{241, 182, 30}},
	{52, atlasColor{249, 244, 174}},
	{53, atlasColor{253, 243, 242}},
	{54, atlasColor{56, 44, 57}},
	{55, atlasColor{20, 112, 75}},
};

