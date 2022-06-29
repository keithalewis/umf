---
title: Library Overview
author: Keith A. Lewis
...

$(D_t)_{t\ge0}$ is stochastic discount. $D_t(u) = E_t[D_u]/D_t$
is price at $t$ of zero coupon bond maturing at $u$.

Forward measure $E_t[X D_u]/D_t = E_t^u[X] E_t[D_u]/D_t = E_t^u[X]D_t(u)$. 

$X_t = E_t[X_u D_u/D_t - \sum_{t < s \le u}C_s D_s/D_t]
= E_t^u[X_u] D_t(u) - \sum_{t < s \le u} E_t^s[C_s] D_t(s)$.

An algebra of sets is a collection of atoms that partition the sample space.

Write $\mathcal{A}\preceq\mathcal{B}$ if for every $B\in\mathcal{B}$ there
exists $A\in\mathcal{A}$ with $B\subseteq A$. 

We write $A\mid B = \{B\in\mathcal{B}\mid B\subseteq A\}$ for $A\in\mathcal{A}$.

$E[X|A] = \sum \{X(A) P(A) \mid A\in\mathcal{A}\}$

- Utility
	- Random number generator
	- Distributions
	- Iterable
	- Basis spline

- Curves
	- Bootstrap
	- LMM


## Trading

Breakout below a, above c, below b, above d, a < b < c < d

S < a, S > c, S < b, S > d | .fst = 3
