#pragma once
#include "Sound.h"
#include <wx/sound.h>
#include <memory>
#include <cstdlib>

class Audio {
	static const std::unique_ptr<wxSound> basic_mirror1;
	static const std::unique_ptr<wxSound> basic_mirror2;
	static const std::unique_ptr<wxSound> basic_mirror3;
	static const std::unique_ptr<wxSound> collected;
	static const std::unique_ptr<wxSound> retractable_mirror_up;
	static const std::unique_ptr<wxSound> retractable_mirror_down;
	static const std::unique_ptr<wxSound> tunnel;
public:
	static void play(Sound);
};

