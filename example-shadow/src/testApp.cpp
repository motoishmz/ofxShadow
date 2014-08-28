#include "testApp.h"

#include "ofxShadow.h"

ofxShadow simple_shadow;

ofEasyCam cam;
ofVec3f light_pos;

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255);
	simple_shadow.setup(&cam);
	
}

//--------------------------------------------------------------
void testApp::update(){

	// updating shadow color using mouse position
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0f, 1.0f);
	ofColor shadow_color = ofFloatColor(0.0f, 0.0f, 0.0f, alpha);
	
	simple_shadow.setShadowColor( shadow_color );
	
	// updating light position
	static const float light_moving_speed = 0.1;
	static const float light_moving_radius = 50;
	
	light_pos = ofVec3f(sin(2.0 * M_PI * (ofGetElapsedTimef()*light_moving_speed)) * light_moving_radius,
								 250,
								 0);
	simple_shadow.setLightPosition(light_pos);
	
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
	
	cam.begin();
	{
		glEnable(GL_DEPTH_TEST);
		
		// axis
		ofDrawAxis(300);
		
		
		// light pos
		ofSetColor(255, 0, 255);
		ofBox(light_pos, 3);
		ofDrawBitmapString("light", light_pos+10);
		
		
		// red box
		ofSetColor(255, 0, 0);
		ofBox(0, 150, 50, 30);
		
		
		// shadow
		simple_shadow.begin();
		ofBox(0, 150, 50, 30);
		simple_shadow.end();
		
		glDisable(GL_DEPTH_TEST);
	}
	cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}