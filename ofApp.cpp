#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto len = 50;
	for (int i = 0; i < 1; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		for (int k = 0; k < 30; k++) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x * 0.03, ofGetFrameNum() * 0.02 + k * 0.02), 0, 1, -320, 320),
				ofMap(ofNoise(noise_seed.y * 0.03, ofGetFrameNum() * 0.02 + k * 0.02), 0, 1, -320, 320));
			auto next_location = glm::vec2(
				ofMap(ofNoise(noise_seed.x * 0.03, ofGetFrameNum() * 0.02 + k * 0.02 + 0.002), 0, 1, -320, 320),
				ofMap(ofNoise(noise_seed.y * 0.03, ofGetFrameNum() * 0.02 + k * 0.02 + 0.002), 0, 1, -320, 320));

			auto deg = atan2(next_location.y - location.y, next_location.x - location.x) * RAD_TO_DEG;

			ofPushMatrix();
			ofTranslate(location);

			auto location_1 = glm::vec2(len * cos((deg + 90) * DEG_TO_RAD), len * sin((deg + 90) * DEG_TO_RAD));
			auto location_2 = glm::vec2(len * cos((deg - 90) * DEG_TO_RAD), len * sin((deg - 90) * DEG_TO_RAD));

			ofSetColor(0, ofMap(k, 0, 30, 32, 255));

			ofDrawLine(location_1, location_2);
			ofDrawCircle(location_1, 3);
			ofDrawCircle(location_2, 3);

			ofPopMatrix();

		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}