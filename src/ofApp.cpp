// http://vector.mapzen.com/osm/all/16/33975/22294.json

// http://www.maptiler.org/google-maps-coordinates-tile-bounds-projection/



#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofEnableDepthTest();
    ofEnableAlphaBlending();

    cam.setNearClip(0.0001f);
    cam.setFarClip(10000.0f);
    // cam.sensitivity = 0.01;
    // cam.upvector = ofVec3f(0, 1, 0);
    cam.toggleControl();
    cam.movespeed = 0.1f;


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


    camera.disableMouseInput();

    JsonLoader jsonLoader = JsonLoader("vectorTile_16_33975_22294.json");
    rootNode = jsonLoader.loadNodeGraph();
    rootNode->setPosition(0, 0, 0);
    camera.setPosition(rootNode->getGlobalPosition());
    camera.move(0, 0, 300);
    camera.setTarget(rootNode->getGlobalPosition());

}



//--------------------------------------------------------------
void ofApp::update() {

    auto pushed = in.keyPushed;
    auto holded = in.keyHolded;
    auto pulled = in.keyPulled;

    if ( pushed[GLFW_KEY_LEFT_SHIFT] ) cam.movespeed = 7.0f;
    if ( pulled[GLFW_KEY_LEFT_SHIFT] ) cam.movespeed = 1.0f;

    if ( pushed[GLFW_MOUSE_BUTTON_LEFT] ) paint.push_back( ofPolyline() );
    if ( holded[GLFW_MOUSE_BUTTON_LEFT] ) paint.back().addVertex( cam.getPosition() + (cam.getLookAtDir() * 50.0f) );

    if ( pushed[GLFW_MOUSE_BUTTON_RIGHT] ) cam.toggleControl();


    camera.lookAt(cam.getLookAtDir());
    camera.setGlobalPosition(cam.getGlobalPosition() + ofVec3f(0, 0, 300));
    camera.setGlobalOrientation(cam.getGlobalOrientation());

    roadMovingFactor_top = roadMovingFactor_top + 4;
    roadMoving_top = sin( ofDegToRad(roadMovingFactor_top) ) * 0.5 + 0.5;

}




//--------------------------------------------------------------
void ofApp::draw() {

    camera.begin();

    ofVec3f _offSetPos = ofVec3f(0, 0, 0);

    drawBuildingsMesh(buildingsMesh_top, ofVec3f(0, 0, _offSetPos.z), ofVec3f(0, 0, 0));
    //    drawBuildingsMesh(buildingsMesh_left, ofVec3f(-_offSetPos.x, 0, 0), ofVec3f(0, -90, 0));
    //    drawBuildingsMesh(buildingsMesh_right, ofVec3f(_offSetPos.x, 0, 0), ofVec3f(0, 90, 0));
    //    drawBuildingsMesh(buildingsMesh_front, ofVec3f(0, _offSetPos.y, 0), ofVec3f(-90, 0, 0));
    //    drawBuildingsMesh(buildingsMesh_back, ofVec3f(0, -_offSetPos.y, 0), ofVec3f(90, 0, 0));
    //    drawBuildingsMesh(buildingsMesh_bottom, ofVec3f(0, 0, -_offSetPos.z), ofVec3f(180, 0, 0));

    drawRoadPolyLineMoving(roadsPolyline_top, ofVec3f(0, 0, _offSetPos.z), ofVec3f(0, 0, 0));
    //    drawRoadPolyLineMoving(roadsPolyline_left, ofVec3f(-_offSetPos.x, 0, 0), ofVec3f(0, -90, 0));
    //    drawRoadPolyLineMoving(roadsPolyline_right, ofVec3f(_offSetPos.x, 0, 0), ofVec3f(0, 90, 0));
    //    drawRoadPolyLineMoving(roadsPolyline_front, ofVec3f(0, _offSetPos.y, 0), ofVec3f(-90, 0, 0));
    //    drawRoadPolyLineMoving(roadsPolyline_back, ofVec3f(0, -_offSetPos.y, 0), ofVec3f(90, 0, 0));
    //    drawRoadPolyLineMoving(roadsPolyline_bottom, ofVec3f(0, 0, -_offSetPos.z), ofVec3f(180, 0, 0));

    camera.end();

    //    ofPushMatrix();
    //
    //    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    //
    //    baseArch.guideFrames();
    //    baseArch.drawEdgeCover( ofColor(0) );
    //    baseArch.guideLines();
    //    baseArch.guidePoints();
    //
    //    ofPopMatrix();

}



//--------------------------------------------------------------
void ofApp::drawBuildingsMesh(vector< ofMesh > _mesh, ofVec3f _position, ofVec3f _rotation) {

    ofPushMatrix();
    ofTranslate( _position );
    ofRotateX(_rotation.x);
    ofRotateY(_rotation.y);
    ofRotateZ(_rotation.z);


    //    ofPushStyle();
    //    ofSetColor(255);
    //    for (int i=0; i<_mesh.size(); i++) {
    //        _mesh[i].draw();
    //    }
    //    ofPopStyle();


    ofPushStyle();

    ofSetColor(255, 255);

    for (int i = 0; i < _mesh.size(); i++) {

        //        ofPushStyle();
        //        ofSetColor(0, 255);
        //        vector<ofVec3f> & _v = _mesh[i].getVertices();
        //        for (int j=0; j<_v.size(); j++) {
        //            ofDrawLine( _v[j] - ofVec3f(0, 0, 0), _v[j] + ofVec3f(0, 0, 10) );
        //        }
        //        ofPopStyle();

        ofBeginShape();
        vector<glm::vec3>& _verticesUp = _mesh[i].getVertices();
        for (int j = 0; j < _verticesUp.size(); j++) {
            ofVec3f _v = _verticesUp[j] + ofVec3f(0, 0, 10);
            ofVertex(_v);
        }
        ofEndShape();

        ofPushStyle();
        ofSetColor(180, 255);
        vector<glm::vec3>& _verticesSide = _mesh[i].getVertices();
        for (int j = _verticesSide.size() - 2; j >= 0; j--) {
            ofBeginShape();
            ofVertex(_verticesSide[j]);
            ofVertex(_verticesSide[j + 1]);
            ofVec3f _v1Up = _verticesSide[j] + ofVec3f(0, 0, 10);
            ofVec3f _v2Up = _verticesSide[j + 1] + ofVec3f(0, 0, 10);
            ofVertex( _v2Up );
            ofVertex( _v1Up );
            ofEndShape();
        }
        ofPopStyle();

        ofBeginShape();
        vector<glm::vec3>& _vertices = _mesh[i].getVertices();
        for (int j = 0; j < _vertices.size() - 1; j++) {
            ofVertex(_vertices[j]);
        }
        ofEndShape();

    }

    ofPopStyle();

    ofPopMatrix();

}


//--------------------------------------------------------------
void ofApp::drawRoadPolyLineMoving(vector< ofPolyline > _ofPolyline, ofVec3f _position, ofVec3f _rotation) {

    ofPushMatrix();

    ofTranslate( _position );
    ofRotateXDeg(_rotation.x);
    ofRotateYDeg(_rotation.y);
    ofRotateZDeg(_rotation.z);

    ofPushStyle();
    ofSetColor(255, 120);

    ofSetLineWidth(1);
    for (int i = 0; i < _ofPolyline.size(); i++) {
        _ofPolyline[i].draw();
    }

    for (int i = 0; i < _ofPolyline.size(); i++) {
        ofDrawCircle(_ofPolyline[i].getPointAtPercent( roadMoving_top ) , 2);
    }

    ofPopStyle();

    ofPopMatrix();

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}



//--------------------------------------------------------------
vector< ofMesh > ofApp::buildingsMesh(string _fileName) {

    vector< ofMesh > _return;

    FeatureNode * _rootNode;

    JsonLoader _jsonLoader = JsonLoader(_fileName);
    _rootNode = _jsonLoader.loadNodeGraph();

    ofxJSONElement _jsonMain;
    _jsonMain = _jsonLoader.jsonRoot;

    ofxJSONElement _jsonBuildings;
    _jsonBuildings = _jsonMain["buildings"]["features"];


    for (int i = 0; i < _jsonBuildings.size(); i++) {
        ofxJSONElement _jsonBuilding;
        _jsonBuilding = _jsonBuildings[i]["geometry"]["coordinates"][0];

        ofMesh _m;
        _m.setMode(OF_PRIMITIVE_LINE_LOOP);

        for (int j = 0; j < _jsonBuilding.size(); j++) {

            ofxJSONElement _coordinateBuilding;
            _coordinateBuilding = _jsonBuilding[j];

            glm::vec3 _v;
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
vector< ofPolyline > ofApp::roadsPolyline(string _fileName) {

    vector< ofPolyline > _return;

    FeatureNode * _rootNode;

    JsonLoader _jsonLoader = JsonLoader(_fileName);
    _rootNode = _jsonLoader.loadNodeGraph();

    ofxJSONElement _jsonMain;
    _jsonMain = _jsonLoader.jsonRoot;

    ofxJSONElement _jsonRoads;
    _jsonRoads = _jsonMain["roads"]["features"];


    for (int i = 0; i < _jsonRoads.size(); i++) {
        ofxJSONElement _jsonRoad;


        string _multiString = _jsonRoads[i]["geometry"]["type"].asString();

        ofPolyline _pl;

        if (_multiString != "MultiLineString") {

            _jsonRoad = _jsonRoads[i]["geometry"]["coordinates"];

            for (int j = 0; j < _jsonRoad.size(); j++) {

                ofxJSONElement _coordinateRoad;
                _coordinateRoad = _jsonRoad[j];

                glm::vec3 _v;
                _v.x = _jsonLoader.lon2x(_jsonRoad[j][0].asFloat()) - _rootNode->getX();
                _v.y = _jsonLoader.lat2y(_jsonRoad[j][1].asFloat()) - _rootNode->getY();

                _pl.addVertex(_v);

            }

            _return.push_back( _pl );


        } else {

            _jsonRoad = _jsonRoads[i]["geometry"]["coordinates"][0];

            for (int j = 0; j < _jsonRoad.size(); j++) {

                ofxJSONElement _coordinateRoad;
                _coordinateRoad = _jsonRoad[j];

                glm::vec3 _v;
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



