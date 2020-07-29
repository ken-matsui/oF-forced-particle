#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int mouseForce = 2; // マウスの引力
    
    // メッシュ
    ofVboMesh mesh;
    
    // パーティクル
    static const int NUM = 100000;
    ofVec2f particlePos[NUM]; // 頂点座標
    ofVec2f particleFor[NUM]; // 力
    ofVec2f particleVel[NUM]; // 速度
};
