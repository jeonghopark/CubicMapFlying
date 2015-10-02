// http://vector.mapzen.com/osm/all/16/33975/22294.json

// http://www.maptiler.org/google-maps-coordinates-tile-bounds-projection/



#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofEnableDepthTest();
    
    
//    gui.setup();
//    gui.add(colorFassade.setup("colorFassade", ofColor(0, 0, 0), ofColor(0, 0), ofColor(255, 255)));
//    gui.add(colorBackground.setup("colorBackground", ofColor(0, 0, 0), ofColor(0, 0), ofColor(255, 255)));
//    gui.add(colorBuilding.setup("colorBuilding", ofColor(255, 255, 255), ofColor(0, 0), ofColor(255, 255)));
//    gui.add(colorStreet.setup("colorStreet", ofColor(255, 255, 255), ofColor(0, 0), ofColor(255, 255)));
//    gui.add(streetWidth.setup("Street Width", 0, 1, 10));
//    gui.add(movingObjectSize.setup("Moving Size", 1, 3, 40));
    
//    originArchBase.load("Fassade IF10 - white_1260x800.png");

    buildingsMesh_top = buildingsMesh("vectorTile_16_33975_22294.json");
    roadsPolyline_top = roadsPolyline("vectorTile_16_33975_22294.json");

    buildingsMesh_left = buildingsMesh("vectorTile_16_33974_22294.json");
    roadsPolyline_left = roadsPolyline("vectorTile_16_33974_22294.json");

    buildingsMesh_right = buildingsMesh("vectorTile_16_33976_22294.json");
    roadsPolyline_right = roadsPolyline("vectorTile_16_33976_22294.json");

    buildingsMesh_front = buildingsMesh("vectorTile_16_33975_22295.json");
    roadsPolyline_front = roadsPolyline("vectorTile_16_33975_22295.json");

    buildingsMesh_back = buildingsMesh("vectorTile_16_33975_22293.json");
    roadsPolyline_back = roadsPolyline("vectorTile_16_33975_22293.json");

    buildingsMesh_bottom = buildingsMesh("vectorTile_16_33975_22296.json");
    roadsPolyline_bottom = roadsPolyline("vectorTile_16_33975_22296.json");

    
    
    camera = ofEasyCam();
//    camera.setPosition(_rootNode_33975_22294->getGlobalPosition());
//    camera.move(0, 0, 300);
//    camera.setTarget(_rootNode_33975_22294->getGlobalPosition());
    
    mainLight = ofLight();
    mainLight.setPointLight();
    mainLight.setGlobalPosition(-100, 0, 500);
    mainLight.setDiffuseColor(ofColor(35, 35, 35));
    mainLight.setSpecularColor(ofColor(170, 170, 170));
    
 
//    fassadeImg.load("Fassade IF10 - white_1260x800.png");
//
//    topleft = ofPoint(100, 100);
//    topright = ofPoint(1180, 100);
//    buttomleft = ofPoint(1180, 700);
//    buttomright = ofPoint(100, 700);
//    
//    
//    quadManager.addQuad(ofPoint(0, 0), ofPoint(fassadeImg.getWidth(), 0), ofPoint(fassadeImg.getWidth(), fassadeImg.getHeight()), ofPoint(0, fassadeImg.getHeight()), topleft, topright, buttomleft, buttomright);
//    quad = quadManager.getQuad(0);
//    
//    ofxQuadSourceImage* imageSource =  new ofxQuadSourceImage(&fassadeImg);
//    quad->setSource(imageSource);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    roadMovingFactor_top = roadMovingFactor_top + 4;
    roadMoving_top = sin( ofDegToRad(roadMovingFactor_top) ) * 0.5 + 0.5;
    
    
//    quadManager.update();

}


//--------------------------------------------------------------
void ofApp::draw(){
    
    //    ofEnableLighting();
    
    
    ofBackground(0);
    ofPopStyle();
    
    camera.begin();
    
    //    mainLight.enable();
    
    ofVec3f _offSetPosition = ofVec3f(540, 540, 540);
    
    drawBuildingsMesh(buildingsMesh_top, ofVec3f(0, 0, _offSetPosition.z), ofVec3f(0, 0, 0));
    drawBuildingsMesh(buildingsMesh_left, ofVec3f(-_offSetPosition.x, 0, 0), ofVec3f(0, 90, 0));
    drawBuildingsMesh(buildingsMesh_right, ofVec3f(_offSetPosition.x, 0, 0), ofVec3f(0, -90, 0));
    drawBuildingsMesh(buildingsMesh_front, ofVec3f(0, _offSetPosition.y, 0), ofVec3f(90, 0, 0));
    drawBuildingsMesh(buildingsMesh_back, ofVec3f(0, -_offSetPosition.y, 0), ofVec3f(-90, 0, 0));
    drawBuildingsMesh(buildingsMesh_bottom, ofVec3f(0, 0, -_offSetPosition.z), ofVec3f(180, 0, 0));

    drawRoadPolyLineMoving(roadsPolyline_top, ofVec3f(0, 0, _offSetPosition.z), ofVec3f(0, 0, 0));
    drawRoadPolyLineMoving(roadsPolyline_left, ofVec3f(-_offSetPosition.x, 0, 0), ofVec3f(0, 90, 0));
    drawRoadPolyLineMoving(roadsPolyline_right, ofVec3f(_offSetPosition.x, 0, 0), ofVec3f(0, -90, 0));
    drawRoadPolyLineMoving(roadsPolyline_front, ofVec3f(0, _offSetPosition.y, 0), ofVec3f(90, 0, 0));
    drawRoadPolyLineMoving(roadsPolyline_back, ofVec3f(0, -_offSetPosition.y, 0), ofVec3f(-90, 0, 0));
    drawRoadPolyLineMoving(roadsPolyline_bottom, ofVec3f(0, 0, -_offSetPosition.z), ofVec3f(180, 0, 0));
    
    
    //    mainLight.disable();
    
    
    camera.end();
    
    //    ofDisableLighting();
    

//    drawEdgeShape();
    
    
    ofPushStyle();

    ofSetColor(0);
//    quadManager.draw();
    
    ofPopStyle();
    
//    quadManager.getQuad(0)->drawOutputConfig();
//    drawEdge();

    
//    if (bGUI) {
//        gui.draw();
//    }

    
    
}

////--------------------------------------------------------------
//void ofApp::drawEdgeShape(){
//    
//    ofPushStyle();
//    
////    ofDisableAlphaBlending();
//    
//    ofPushStyle();
//    
////    ofSetColor(255, 255);
//    originArchBase.draw(0, 400-305);
//    
//    ofPopStyle();
//
//    ofSetColor(0);
//    ofDrawRectangle( 0, 0, ofGetWidth(), 400-305 );
//    ofDrawRectangle( 0, 400-305 + 610, ofGetWidth(), 400-305 );
//    
////    ofEnableAlphaBlending();
//    
//    ofPopStyle();
//    
//}

//--------------------------------------------------------------
void ofApp::drawBuildingsMesh(vector< ofMesh > _mesh, ofVec3f _position, ofVec3f _rotation){
    
    ofPushMatrix();
    
    ofTranslate( _position );

    ofRotateX(_rotation.x);
    ofRotateY(_rotation.y);
    ofRotateZ(_rotation.z);
    
    ofPushStyle();
    ofSetColor(255, 80);

//    for (int i=0; i<_mesh.size(); i++) {
//        _mesh[i].draw();
//    }
    
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(255, 160);
    
    for (int i=0; i<_mesh.size(); i++) {
        vector<ofVec3f> & _v = _mesh[i].getVertices();
        for (int j=0; j<_v.size(); j++) {
            ofDrawLine( _v[j] - ofVec3f(0, 0, 0), _v[j] + ofVec3f(0, 0, 100) );
        }
        
        ofBeginShape();
        vector<ofVec3f>& vertices = _mesh[i].getVertices();
        for(int j = 0; j < vertices.size(); j++) {
            ofVertex(vertices[j]);
        }
        ofEndShape();
        
        ofBeginShape();
        vector<ofVec3f>& verticesUp = _mesh[i].getVertices();
        for(int j = 0; j < verticesUp.size(); j++) {
            ofVec3f _v = verticesUp[j] + ofVec3f(0, 0, 100);
            ofVertex(_v);
        }
        ofEndShape();
        
    }
    
    ofPopStyle();

    ofPopMatrix();

}


//--------------------------------------------------------------
void ofApp::drawRoadPolyLineMoving(vector< ofPolyline > _ofPolyline, ofVec3f _position, ofVec3f _rotation){
    
    ofPushMatrix();
    
    ofTranslate( _position );
    
    ofRotateX(_rotation.x);
    ofRotateY(_rotation.y);
    ofRotateZ(_rotation.z);
    
    
    
    ofPushStyle();
    ofSetColor(255, 120);

    ofSetLineWidth(1);
    for (int i=0; i<_ofPolyline.size(); i++) {
        _ofPolyline[i].draw();
    }
    
    for (int i=0; i<_ofPolyline.size(); i++) {
        ofDrawCircle(_ofPolyline[i].getPointAtPercent( roadMoving_top ) , 2);
    }
    

    ofPopStyle();
    
    
    ofPopMatrix();
    
}



////--------------------------------------------------------------
//void ofApp::drawEdge(){
//    
//    
//    ofPushStyle();
//    ofSetColor(0, 0, 0);
//    
//    ofPoint _topLeft = quadManager.getQuad(0)->getOutputPoint(0);
//    ofPoint _topRight = quadManager.getQuad(0)->getOutputPoint(1);
//    ofPoint _bottomRight = quadManager.getQuad(0)->getOutputPoint(2);
//    ofPoint _bottomLeft = quadManager.getQuad(0)->getOutputPoint(3);
//    
//    ofPolyline _left;
//    _left.addVertex( ofVec2f(0, 0) );
//    _left.addVertex( _topLeft );
//    _left.addVertex( _bottomLeft );
//    _left.addVertex( ofVec2f(0, ofGetHeight()) );
//    
//    ofBeginShape();
//    vector<ofVec3f>& _verticesLeft = _left.getVertices();
//    for(int j = 0; j < _verticesLeft.size(); j++) {
//        ofVertex(_verticesLeft[j]);
//    }
//    ofEndShape();
//    
//    
//    ofPolyline _up;
//    _up.addVertex( ofVec2f(0, 0) );
//    _up.addVertex( ofVec2f(ofGetWidth(), 0) );
//    _up.addVertex( _topRight );
//    _up.addVertex( _topLeft );
//    
//    ofBeginShape();
//    vector<ofVec3f>& _verticesUp = _up.getVertices();
//    for(int j = 0; j < _verticesUp.size(); j++) {
//        ofVertex(_verticesUp[j]);
//    }
//    ofEndShape();
//    
//    ofPolyline _right;
//    _right.addVertex( _topRight );
//    _right.addVertex( ofVec2f(ofGetWidth(), 0) );
//    _right.addVertex( ofVec2f(ofGetWidth(), ofGetHeight()) );
//    _right.addVertex( _bottomRight );
//    
//    ofBeginShape();
//    vector<ofVec3f>& _verticesRight = _right.getVertices();
//    for(int j = 0; j < _verticesRight.size(); j++) {
//        ofVertex(_verticesRight[j]);
//    }
//    ofEndShape();
//    
//    ofPolyline _bottom;
//    _bottom.addVertex( _bottomLeft );
//    _bottom.addVertex( _bottomRight );
//    _bottom.addVertex( ofVec2f(ofGetWidth(), ofGetHeight()) );
//    _bottom.addVertex( ofVec2f(0, ofGetHeight()) );
//    
//    ofBeginShape();
//    vector<ofVec3f>& _verticesBottom = _bottom.getVertices();
//    for(int j = 0; j < _verticesBottom.size(); j++) {
//        ofVertex(_verticesBottom[j]);
//    }
//    ofEndShape();
//    
//    
//    ofPopStyle();
//    
//    
//    ofPushStyle();
//
//    ofSetColor(0, 255, 0);
//    
//    ofDrawCircle(_topLeft, 5);
//    ofDrawCircle(_topRight, 5);
//    ofDrawCircle(_bottomRight, 5);
//    ofDrawCircle(_bottomLeft, 5);
//    
//    ofPopStyle();
//    
//}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 
//    if (key == '1') {
//        topleft = ofPoint( mouseX, mouseY );
//    }
//    if (key == '2') {
//        topright = ofPoint( mouseX, mouseY );
//    }
//    if (key == '3') {
//        buttomright = ofPoint( mouseX, mouseY );
//    }
//    if (key == '4') {
//        buttomleft = ofPoint( mouseX, mouseY );
//    }

//    if (key == 'g') {
//        bGUI = !bGUI;
//    }
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
//    if ((key =='1') || (key =='2') || (key =='3') || (key =='4')) {
//        quad->setOutputPoints(topleft, topright, buttomright, buttomleft);
//    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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



//--------------------------------------------------------------
vector< ofMesh > ofApp::buildingsMesh(string _fileName){

    vector< ofMesh > _return;
    
    FeatureNode * _rootNode;
    
    JsonLoader _jsonLoader = JsonLoader(_fileName);
    _rootNode = _jsonLoader.loadNodeGraph();
    
    ofxJSONElement _jsonMain;
    _jsonMain = _jsonLoader.jsonRoot;
    
    ofxJSONElement _jsonBuildings;
    _jsonBuildings = _jsonMain["buildings"]["features"];
    
    
    for (int i=0; i<_jsonBuildings.size(); i++) {
        ofxJSONElement _jsonBuilding;
        _jsonBuilding = _jsonBuildings[i]["geometry"]["coordinates"][0];
        
        ofMesh _m;
        _m.setMode(OF_PRIMITIVE_LINE_LOOP);
        
        for (int j=0; j<_jsonBuilding.size(); j++) {
            
            ofxJSONElement _coordinateBuilding;
            _coordinateBuilding = _jsonBuilding[j];
            
            ofVec2f _v;
            _v.x = _jsonLoader.lon2x(_coordinateBuilding[0].asFloat()) - _rootNode->getX();
            _v.y = _jsonLoader.lat2y(_coordinateBuilding[1].asFloat()) - _rootNode->getY();
            
            _m.addVertex(_v);
            _m.addColor( ofColor(255) );
            
        }
        
        _return.push_back( _m );
    
    }
    
    _rootNode->setPosition(0, 0, 0);
//    _rootNode->printPosition("");
    
    return _return;
    
}


//--------------------------------------------------------------
vector< ofPolyline > ofApp::roadsPolyline(string _fileName){
    
    vector< ofPolyline > _return;
    
    FeatureNode * _rootNode;
    
    JsonLoader _jsonLoader = JsonLoader(_fileName);
    _rootNode = _jsonLoader.loadNodeGraph();
    
    ofxJSONElement _jsonMain;
    _jsonMain = _jsonLoader.jsonRoot;

    ofxJSONElement _jsonRoads;
    _jsonRoads = _jsonMain["roads"]["features"];
    
    
    for (int i=0; i<_jsonRoads.size(); i++) {
        ofxJSONElement _jsonRoad;
        
        
        string _multiString = _jsonRoads[i]["geometry"]["type"].asString();
        
        ofPolyline _pl;
        
        if (_multiString != "MultiLineString") {
            
            _jsonRoad = _jsonRoads[i]["geometry"]["coordinates"];
            
            for (int j=0; j<_jsonRoad.size(); j++) {
                
                ofxJSONElement _coordinateRoad;
                _coordinateRoad = _jsonRoad[j];
                
                ofVec2f _v;
                _v.x = _jsonLoader.lon2x(_jsonRoad[j][0].asFloat()) - _rootNode->getX();
                _v.y = _jsonLoader.lat2y(_jsonRoad[j][1].asFloat()) - _rootNode->getY();
                
                _pl.addVertex(_v);
                
            }
            
            _return.push_back( _pl );
            
            
        } else {
            
            _jsonRoad = _jsonRoads[i]["geometry"]["coordinates"][0];
            
            for (int j=0; j<_jsonRoad.size(); j++) {
                
                ofxJSONElement _coordinateRoad;
                _coordinateRoad = _jsonRoad[j];
                
                ofVec2f _v;
                _v.x = _jsonLoader.lon2x(_jsonRoad[j][0].asFloat()) - _rootNode->getX();
                _v.y = _jsonLoader.lat2y(_jsonRoad[j][1].asFloat()) - _rootNode->getY();
                
                _pl.addVertex(_v);
                
            }
            
            _return.push_back( _pl );
            
        }
        
    }
    
    
    _rootNode->setPosition(0, 0, 0);
    //    _rootNode->printPosition("");
    
    return _return;
    
}



