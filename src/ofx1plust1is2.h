//
//  ofx1plust1is2.h
//
//  Created by ISHII 2bit on 2014/12/29.
//
//

#pragma once

#include "ofMain.h"

#include "ofx1plus1is2Eq.h"
#include "ofx1plus1is2Nat.h"

class ofx1plust1is2 {
public:
    void setup() {
        // +(s(0), s(0)) == s(+(s(0), 0)
        Eq<Add<Suc<Zero>, Suc<Zero> >, Suc<Add<Suc<Zero>, Zero> > > proof1 = Axiom::PA::add_m_sn_is_s_add_m_n<Suc<Zero>, Zero>();
        
        // +(s(0), 0) == s(0)
        Eq<Add<Suc<Zero>, Zero>, Suc<Zero> > proof2 = Axiom::PA::add_m_0_is_m<Suc<Zero> >();
        
        // s(+(s(0), 0) == s(s(0))
        Eq<Suc<Add<Suc<Zero>, Zero> >, Suc<Suc<Zero> > > proof3 = Axiom::PA::suc(proof2);
        
        // +(s0), s(0)) == s(s(0))
        Eq<Add<Suc<Zero>, Suc<Zero> >, Suc<Suc<Zero> > > proof1plus1is2 = Axiom::Equality::transitive(proof1, proof3);
    }
    
    void update() {
        if(1 + 1 != 2) ofExit(-1);
    }
    
    void draw() {
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("1 + 1 = 2", 10, 10);
    }
};