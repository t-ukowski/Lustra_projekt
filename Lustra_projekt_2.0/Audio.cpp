#include "Audio.h"

const std::unique_ptr<wxSound> Audio::basic_mirror1 = std::make_unique<wxSound>(_T(".\\data\\sounds\\basic_mirror1.wav"), false);
const std::unique_ptr<wxSound> Audio::basic_mirror2 = std::make_unique<wxSound>(_T(".\\data\\sounds\\basic_mirror2.wav"), false);
const std::unique_ptr<wxSound> Audio::basic_mirror3 = std::make_unique<wxSound>(_T(".\\data\\sounds\\basic_mirror3.wav"), false);
const std::unique_ptr<wxSound> Audio::collected = std::make_unique<wxSound>(_T(".\\data\\sounds\\collected.wav"), false);
const std::unique_ptr<wxSound> Audio::retractable_mirror_up = std::make_unique<wxSound>(_T(".\\data\\sounds\\retractable_mirror_up.wav"), false);
const std::unique_ptr<wxSound> Audio::retractable_mirror_down = std::make_unique<wxSound>(_T(".\\data\\sounds\\retractable_mirror_down.wav"), false);
const std::unique_ptr<wxSound> Audio::tunnel = std::make_unique<wxSound>(_T(".\\data\\sounds\\tunnel.wav"), false);

void Audio::play(Sound s) {
	int r = rand();
	switch(s) {
	case(Sound::BASIC_MIRROR):
		switch (r % 3) {
		case(0):
			basic_mirror1->Play();
			break;
		case(1):
			basic_mirror2->Play();
			break;
		case(2):
			basic_mirror3->Play();
			break;
		default:
			break;
		}
		break;
	case(Sound::RETRACTABLE_MIRROR_DOWN):
		retractable_mirror_down->Play();
		break;
	case(Sound::RETRACTABLE_MIRROR_UP):
		retractable_mirror_up->Play();
		break;
	case(Sound::COLLECTED):
		collected->Play();
		break;
	case(Sound::TUNNEL):
		tunnel->Play();
		break;
	}
}
