#include "Audio.h"

void Audio::SetPlaybackSpeed(uint32_t voiceHandle, float speed) {
	std::lock_guard<std::mutex> lock(voiceMutex_);
	for (Voice* voice : voices_) {
		if (voice->handle == voiceHandle && voice->sourceVoice) {
			voice->sourceVoice->SetFrequencyRatio(speed);
			break;
		}
	}
}