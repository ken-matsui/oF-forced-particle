#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1.0);
    
    // パーティクルの初期化
    for (int i = 0; i < NUM; i++) {
        particlePos[i] = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        particleVel[i] = ofVec2f(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (mouseForce == true){ // 反発力
        float radius = ofGetWidth();
        float scale = 0.1;
        
        // 力の中心点(マウスポインタ座標)
        ofVec2f posOfForce;
        posOfForce.set(ofGetMouseX(), ofGetMouseY());
        
        for (int i = 0; i < NUM; i++){
            // 力をリセット
            particleFor[i] = ofVec2f(0, 0);
            // 摩擦力
            particleFor[i] -= particleVel[i] * ofVec2f(0.002, 0.002);
            
            // マウスポインタの圧力
            // パーティクルとマウスポインタの2点間の距離
            ofVec2f diff = particlePos[i] - posOfForce;
            float distance = diff.length();
            
            // 力が働く範囲かどうか判定する
            bool bAmCloseEnough = true;
            
            // もし設定した半径より外側だったら、計算しない
            if (radius > 0){
                if (distance > radius){
                    bAmCloseEnough = false;
                }
            }
            
            // 設定した半径の内側だったら
            if (bAmCloseEnough == true){
                // 距離から点にかかる力ベクトルを計算
                float pct = 1 - (distance / radius);
                
                diff.normalize();
                particleFor[i].x += diff.x * scale * pct;
                particleFor[i].y += diff.y * scale * pct;
            }
            
            // 位置
            particleVel[i] += particleFor[i];
            particlePos[i] += particleVel[i];
            
            
            
            // 画面外にでると反対側から出る
            if (particlePos[i].x < 0){
                particlePos[i].x = ofGetWidth();
            }
            if (particlePos[i].x > ofGetWidth()){
                particlePos[i].x = 0;
            }
            if (particlePos[i].y < 0){
                particlePos[i].y = ofGetHeight();
            }
            if (particlePos[i].y > ofGetHeight()){
                particlePos[i].y = 0;
            }
        }
    }
    else if (mouseForce == false) { // 引力
        float radius = ofGetWidth();
        float scale = 0.1;
        
        // 力の中心点(マウスポインタ座標)
        ofVec2f posOfForce;
        posOfForce.set(ofGetMouseX(), ofGetMouseY());
        
        for (int i = 0; i < NUM; i++){
            // 力をリセット
            particleFor[i] = ofVec2f(0, 0);
            // 摩擦力
            particleFor[i] -= particleVel[i] * ofVec2f(0.002, 0.002);
            
            // マウスポインタの圧力
            // パーティクルとマウスポインタの2点間の距離
            ofVec2f diff = particlePos[i] - posOfForce;
            float distance = diff.length();
            
            // 力が働く範囲かどうか判定する
            bool bAmCloseEnough = true;
            
            // もし設定した半径より外側だったら、計算しない
            if (radius > 0){
                if (distance > radius){
                    bAmCloseEnough = false;
                }
            }
            
            // 設定した半径の内側だったら
            if (bAmCloseEnough == true){
                // 距離から点にかかる力ベクトルを計算
                float pct = 1 - (distance / radius);
                
                diff.normalize();
                particleFor[i].x -= diff.x * scale * pct;
                particleFor[i].y -= diff.y * scale * pct;
            }
            
            // 位置
            particleVel[i] += particleFor[i];
            particlePos[i] += particleVel[i];
            
            
            
            // 画面外にでると反対側から出る
            if (particlePos[i].x < 0){
                particlePos[i].x = ofGetWidth();
            }
            if (particlePos[i].x > ofGetWidth()){
                particlePos[i].x = 0;
            }
            if (particlePos[i].y < 0){
                particlePos[i].y = ofGetHeight();
            }
            if (particlePos[i].y > ofGetHeight()){
                particlePos[i].y = 0;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // メッシュの描画
    mesh.clear();
    ofSetColor(255);
    for (int i = 0; i < NUM; i++) {
        mesh.addVertex(ofVec3f(particlePos[i].x, particlePos[i].y, 0));
    }
    mesh.draw();
    
    // マウス追跡パーティクルの描画
    if (mouseForce) {
        ofSetColor(255, 0, 0);
    }
    else {
        ofSetColor(0, 255, 255);
    }
    ofDrawCircle(mouseX, mouseY, 5);
    
    // ログを表示
    ofSetColor(255, 255, 255);
    string info = ofToString(ofGetFrameRate(), 2) + "\n";
    info += "Particle Count: " + ofToString(100000) + "\n";
    info += "mouseForce : " + ofToString(mouseForce) + "\n";
    ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseForce = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouseForce = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
