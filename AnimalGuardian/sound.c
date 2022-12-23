#include "sound.h"
#include <fmod.h>
#include <stdio.h>
#include <Windows.h>

FMOD_SYSTEM *g_System; //FMOD system 변수선언
FMOD_SOUND *g_Sound[5];
FMOD_CHANNEL *channel=NULL;
FMOD_CHANNEL *channel2 = NULL;

FMOD_BOOL IsPlaying;
FMOD_BOOL Paused = FALSE;



float volume = 0.5; //볼륨 0~1 


void Init(void)
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 10, FMOD_INIT_NORMAL, NULL); //최대 10개의 소리재생가능 

	/*사운드 생성*/
	FMOD_System_CreateSound(g_System, ".\\sound\\main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	FMOD_System_CreateSound(g_System, ".\\sound\\shoot.wav", FMOD_DEFAULT, 0, &g_Sound[1]);
	FMOD_System_CreateSound(g_System, ".\\sound\\playing.wav", FMOD_LOOP_NORMAL, 0, &g_Sound[2]);

}



void StopSound()
{
	FMOD_Channel_Stop(channel); //채널의 소리 모두정지 
	FMOD_Channel_Stop(channel2);
}


void VolumeSetSound(void)
{
	FMOD_Channel_SetVolume(channel, volume); //설정 볼륨으로 소리크기 지정 
}


void SoundUpdate(void)
{
	if (IsPlaying == 1)
		FMOD_System_Update(g_System);
}



void SoundPaused(void) {
	//Paused = !Paused;
	FMOD_Channel_SetPaused(channel2, Paused);
}

/*-----해당 사운드 재생-----*/
void Sound_Play(int n)
{	if(n==2)
		FMOD_System_PlaySound(g_System, g_Sound[n], NULL, 0, &channel2);
	else
		FMOD_System_PlaySound(g_System, g_Sound[n], NULL, 0, &channel);
}

void Release()

{
	for(int i=0;i<5;i++)
		FMOD_Sound_Release(g_Sound[i]);

	FMOD_System_Close(g_System);

	FMOD_System_Release(g_System);

}

