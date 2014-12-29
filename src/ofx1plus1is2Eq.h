//
//  ofx1plus1is2Eq.h
//  ofx1plus1is2Example
//
//  Created by ISHII 2bit on 2014/12/29.
//
//

#pragma once

namespace Axiom {
    class Equality;
    class PA;
};

template<typename S, typename T>
class Eq {
private:
    Eq() {};
    friend Axiom::Equality;
    friend Axiom::PA;
};

namespace Axiom {
    class Equality {
    public:
        // m = m
        template<typename S>
        static Eq<S, S> reflexive() { return Eq<S, S>(); };
        
        // m = n -> n = m
        template<typename S, typename T>
        static Eq<S, T> symmetric(Eq<T, S>) { return Eq<S, T>(); };
        
        // m = n, n = k -> m = k
        template <typename S, typename T, typename U>
        static Eq<S, U> transitive(Eq<S, T>&, Eq<T, U>&) { return Eq<S, U>(); };
    };
};