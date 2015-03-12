#pragma once
#include "ofMain.h"

class ofxShadow
{
public:
	
	void setup(ofCamera *camera);
	void setLightPosition(const ofVec3f& pos);
	void setLightPosition(const ofVec4f& pos);
	void setShadowColor(ofFloatColor color);
	void setShadowAlpha(float alpha);
	
	void begin();
	void end();
	
protected:
	
	ofMatrix4x4 shadow_matrix;
	ofShader shader;
	ofCamera* cam;
	ofFloatColor shadow_color;
};