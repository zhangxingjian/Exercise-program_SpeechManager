#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
using namespace std;

class SpeechManager {
public:

	SpeechManager();

	void show_Menu();
	void exitSystem();

	void initSpeech();

	void createSpeaker();



	~SpeechManager();


	vector<int>v1;

	vector<int>v2;

	vector<int>vVictory;

	map<int, Speaker>m_Speaker;

	int m_Index;

};