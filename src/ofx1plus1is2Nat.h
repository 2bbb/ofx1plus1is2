//
//  ofx1plus1is2Nat.h
//
//  Created by ISHII 2bit on 2014/12/29.
//
//

#pragma once

#include "ofx1plus1is2Eq.h"

class Zero {};

template<typename S>
class Suc {};

template<typename S, typename T>
class Add {};

namespace Axiom {
    class PA {
    public:
        // m = n -> s(m) = s(n)
        template<typename S, typename T>
        static Eq<Suc<S>, Suc<T> > suc(Eq<S, T>&) { return Eq<Suc<S>, Suc<T> >(); };
        
        // add(m, 0) = m
        template<typename S>
        static Eq<Add<S, Zero>, S > add_m_0_is_m() { return Eq<Add<S, Zero>, S>(); };
        
        // add(m, s(n)) = s(add(m, n))
        template<typename S, typename T>
        static Eq<Add<S, Suc<T> >, Suc<Add<S, T> > > add_m_sn_is_s_add_m_n() { return Eq<Add<S, Suc<T> >, Suc<Add<S, T> > >(); };
    };
};