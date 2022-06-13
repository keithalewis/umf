---
title: Linear Algebra
...

\newcommand\RR{\boldsymbol{R}}
\newcommand\CC{\boldsymbol{C}}
\newcommand\FF{\boldsymbol{F}}
\newcommand\zero{\boldsymbol{0}}
\renewcommand\ker{\operatorname{ker}}
\newcommand\ran{\operatorname{ran}}
\renewcommand\span{\operatorname{span}}

Linear algebra is the study of linear structures and functions that
preserve this structure.  Vector spaces are a mathematical sweet
spot. They are completely characterized by their dimension.
Linear operators between vector spaces have a Jordan canonical form.

## Vector Space

A _vector space_ over the real numbers $\RR$ is set $V$ with
a binary operation $V\times V\to V$, $(v,w)\mapsto v + w$, and
a scalar product $\RR\times V\to V$, $(a,v)\mapsto av$, satisfying the distributive law.
The binary addition is _commutative_ ($v + w = w + v$),
_associative_ ($(u + v) + w = u + (w + v)$), has an _identity element_
$\zero$ ($v + \zero = v$), and each element has an inverse ($(-v) + v = \zero$).
The scalar product satisfies the _distributive laws_
$a(v + w) = av + aw$, $(a + b)v = av + bv$, $(ab)v = a(bv)$ and $1v = v$,
$a,b\in\RR$, $v,w\in V$.

__Exercise__. _Show $a\zero = \zero$, $0v = \zero$, and $(-1)v = -v$, $a\in\RR$, $v\in V$_.

If $S$ is any set then the set of all functions from $S$ to
the real numbers, $\RR^S = \{v\colon S\to\RR\}$, is a vector space.
The addition is defined pointwise
$$
	(v + w)(s) = v(s) + w(s)\text{ for } v, w\in\RR^S
$$ 
as is the scalar product 
$$
	(av)(s) = av(s)\text{ for } a\in\RR, v\in\RR^S.
$$

The additive identity, $\zero$, is the function $\zero(s) = 0$ for all $s\in S$.

__Exercise__. _Show $\RR^S$ is a vector space_.

<!--

__Exercise__. (Abelian group under addition) _For $u, v, w\in\RR^S$ prove_
$$
\begin{aligned}
\text{(commutative)}\quad&& v + w &= w + v \\
\text{(associative)}\quad&& (u + v) + w &= u + (w + v)  \\
\text{(identity)}\quad&& \zero + v = &\ v = v + \zero \\
\text{(inverse)}\quad&& (-v) + v = &\ \zero = v + (-v) \\
\end{aligned}
$$

_Hint_. $\RR$ is a abelian group under addition.

__Exercise__. (Scalar multiplication) _For $v\in\RR^S$ and $a,b\in\RR$ prove_
$$
\begin{aligned}
0v &= \zero \\
1v &= v \\
(ab)v &= a(bv) \\
\end{aligned}
$$

__Exercise__. (Distributive laws) _For $a,b\in\RR$ and $v,w\in\RR^S$ prove_
$$
\begin{aligned}
a(v + w) &= av + aw \\
(a + b)v &= av + bv \\
\end{aligned}
$$

<details>
<summary>Solution</summary>
We have $(a(v + w))(s) = a((v + w)(s)) = a(v(s) + w(s)) = av(s) + aw(s) = (av + aw)(s)$
and $(a + b)v(s) = av(s) + bv(s)$, $s\in S$,
by the distributive law for real numbers.
</details>
-->
You are probably already familiar with the vector space
$\RR^n = \{(x_1,\ldots,x_n)\mid x_i\in\RR, 1\le i\le n\}$.
If $S = \{1,\ldots,n\}$ and $x\in\RR^S$ then $x(i) = x_i$
provides a correspondance between $\RR^{\{1,\ldots,n\}}$ and $\RR^n$.

## Subspace

A subset $W\subseteq V$ is a _subspace_ of $V$ if $W$ is also a vector space.
Clearly $\{0\}$ is the smallest subspace and $V$ is the largest subspace of $V$.

__Exercise__. _If $v\in V$ then $\RR v = \{av\mid a\in\RR\}$ is a subspace_.

Given any set $S\subset V$ define $\span S$ to be the smallest
subspace containing $S$.

__Exercise__. _If $S\subseteq V$ then
$\span S = \{\sum_{s\in S_0} a_s s\mid a_s\in\RR, S_0\subseteq S \text{ finite }\}$_.

We need $S_0$ to be finite for the sum to be defined.

<details>
<summary>Solution</summary>
Taking $S_0 = \{s\}$ and $a_s = 1$ we see $S$ is a subset of the right hand side.
Every term of the form $\sum_{s\in S_0} a_s s$ must belong to $\span S$.
Since the right hand side is a subspace it must be equal to the span of $S$.
</details>

A set of vectors $\{v_i\}_{i\in I}$ are _independent_ if
every finite sum $\sum_i a_i v_i = 0$ implies $a_i = 0$ for all $i$.
A _basis_ of a vector space is a set of independent vectors that span $V$.

## Linear Operators

A _linear operator_ from the vector space $V$ to the vector space $W$,
$T\colon V\to W$, is a function that preserves the
vector space structure: $T(u + v) = Tu + Tv$ and $T(au) = aTu$ for
$u,v\in V$, and $a\in\RR$.

__Exercise__. _Show $T(au + v) = aTu + v$, $a\in\RR$, $u,v\in V$ implies $T$ is a linear operator_.

If $T\colon V\to V$ is a linear operator and $U$ is a subspace of $V$
then it is _invariant_ under $T$ if $TW\subseteq W$.

The set of all linear operators from a vector space $V$ 
to a vector space $W$, $\mathcal{L}(V,W)$, is also a vector space. The addition is defined by
$(S + T)v = Sv + Tv$, $S,T\in\mathcal{L}(V,W)$, $v\in V$ and scalar multiplication
by $(aT)v = a(Tv)$, $a\in\RR$.

__Exercise__. _Show  $\mathcal{L}(V,W)$ is a vector space_.

The _kernel_ of a linear transformation $T\colon V\to W$ 
is $\ker T = \{v\in V\mid Tv = 0\}$ and
the _range_ is $\ran T = \{Tv\mid v\in V\} \subseteq W$.

__Exercise__. _If $T\colon V\to W$ is a linear operator show the kernel is a subspace of $V$
and the range is a subspace of $W$_.

__Exercise__. _Show $\ker T = \{0\}$ implies $T$ is one-to-one_.

_Hint_: Show $Tu = Tv$ imples $u = v$, $u,v\in V$.

If $T\colon V\to W$ is one-to-one we can define the inverse
$T^{-1}\colon\ran T\to V$ by $T^{-1}w = v$ if and only if $w = Tv$.

__Exercise__. _If $T\colon V\to V$ is a linear operator then the
kernel and range are invariant under $T$_.

<details>
<summary>Solution</summary>
We have $T(\ker T) = \{\zero\}\subseteq\ker T$ and $T(\ran T) = T(TV)\subseteq TV = \ran T$.
</details>

### Eigenvectors/values

If $T\colon V\to V$ is a linear operator and $\RR v$ is invariant under $T$ then
$v$ is an _eigenvector_ of $T$. The number $\lambda\in\RR$ with $Tv = \lambda v$
is the _eigenvalue_ corresponding to $v$.
Note if $Tv = \lambda v$ then $v\in\ker T - \lambda I\neq \{0\}$
and so $T - \lambda I$ is not invertible.

The _spectrum_ of an operator is the set of all eigenvalues: $\sigma(T) 
= \{\lambda\in\RR\mid \ker(T - \lambda I) \not=\{\zero\}\}$.
For $\lambda\in\sigma(T)$ let $V_\lambda = \ker (T - \lambda I)$.

__Exercise__. _Show $V_\lambda\cap V_\mu = \{\zero\}$ if $\lambda\not=\mu$_.

For $v\in V$ let $V_v = \span\{T^jv\mid j\ge0\}$. Clearly $V_v$ is invariant for $T$.

_Spectral mapping theorem_ If $p$ is a polynomial then $p(\sigma(T)) = \sigma(p(T))$.

### Shift Operator

Given $v_1,\ldots,v_n\in V$ define the _shift operator_ $J\colon V\to V$ 
by $Jv_i = v_{i+1}$, $1\le j < n$ and $Jv_n = \zero$.
