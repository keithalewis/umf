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
\newcommand\qed{$\square$}

Linear algebra is the study of linear structures and functions that
preserve this structure.  Vector spaces are a mathematical sweet
spot. They are completely characterized by their dimension.
Every vector space is isomorphic to $\RR^n$ where $n$ is the dimension.

## Vector Space

A _vector space_ over the real numbers $\RR$ is set $V$ with
a binary operation $V\times V\to V$, $(v,w)\mapsto v + w$, and
a scalar product $\RR\times V\to V$, $(a,v)\mapsto av$, satisfying the distributive law.
The binary addition is _commutative_ ($v + w = w + v$),
_associative_ ($(u + v) + w = u + (w + v)$), has an _identity element_
$\zero$ ($v + \zero = v$), and each element has an inverse ($v + (-v) = \zero$).
The scalar product satisfies the _distributive laws_
$a(v + w) = av + aw$, $(a + b)v = av + bv$, $(ab)v = a(bv)$, $a,b\in\RR$, $v,w\in V$.
We also require $1v = v$ and $av = va$ for $a\in\RR$ and $v\in V$.

__Exercise__. _If $v + z = v$ for all $v\in V$ then $z = \zero$_.

This shows the additive identity is unique.

<details>
<summary>Solution</summary>
Taking $v = \zero$, $z = \zero + z = \zero$.
</details>

__Exercise__. _If $v + v = v$ then $v = \zero$_.

_Hint_. $v + (-v) = \zero$.

__Exercise__. _Show $0v = \zero$,
$a\zero = \zero$,
and $(-1)v = -v$, $a\in\RR$, $v\in V$_.

<details>
<summary>Solution</summary>
Note $0v + 0v = (0 + 0)v = 0v$ so $0v = \zero$.
If $a\not=0$ then for any $v\in V$ we have 
$v + a\zero = aa^{-1}v + a\zero = a(a^{-1}v + \zero) = aa^{-1}v = v$ so $a\zero = \zero$
since the identity is unique.
Since $v + (-1)v = 1v + (-1)v = (1 + (-1))v) = 0v = \zore$ we have $(-1)v = -v$.
</details>

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
The _Kronecker delta_ is $\delta_{ij} = 1$ if $i = j$ and
$\delta_{ij} = 0$ if $i \not= j$. The _standard basis_ in $\RR^n$
is $\{e_j\}_{1\le j\le n}\subset\RR^n$ where $(e_j)_i = \delta_{ij}$, $1\le i\le n$.

__Exercise__. _Show every vector $x = (x_1,\ldots,x_n)\in\RR^n$ can be written
using the standard basis as $x = \sum_j x_j e_j$_.

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

If $v_1, \ldots, v_n$ is a basis for $V$ we can define a linear operator
$T\colon V\to \RR^n$ by $Tv_i = e_i$ where $\{e_i\}$ is the standard basis of $\RR^n$.
By linearity $T(\sum_i a_i v_i) = \sum_i a_i e_i = (a_1,\ldots,a_n)\in\RR^n$.

__Exercise__ _Show $T$ is one-to-one and onto_.

_Hint_. _Onto_ means $\ran T = \RR^n$.

If $T\colon V\to W$ is one-to-one and onto then $T$ is an _isomorphism_.
We say $V$ and $W$ are isomorphic and write $V\cong W$.
Isomorphism is an _equivalence relation_ on vector spaces.

__Exercise__. _Show $V\cong V$, $V\cong W$ implies $W\cong V$,
and $U\cong V$, $V\cong W$ imply $U\cong W$_.

<details>
<summary>Solution</summary>
The identity function $I\colon V\to V$ is an isomorphism. If $T\colon V\to W$
is an isomorphism then so is $T^{-1}W\to V$. If $S\colon U\to V$ and
$T\colon V\to W$ are isomorphisms then so is the composition
$TS\colon U\to W$.
</details>

The fundamental theorem of linear algebra is that two vector spaces are
isomorphic if and only if they have the same dimension.

### Eigenvectors/values

If $T\colon V\to V$ is a linear operator and $\RR v$ is invariant under $T$ then
$v$ is an _eigenvector_ of $T$. The number $\lambda\in\RR$ with $Tv = \lambda v$
is the _eigenvalue_ corresponding to $v$.
Note if $Tv = \lambda v$ then $v\in\ker T - \lambda I\neq \{0\}$
and so $T - \lambda I$ is not invertible.

The _spectrum_ of an operator is the set of all eigenvalues: $\sigma(T) 
= \{\lambda\in\RR\mid \ker(T - \lambda I) \not=\{\zero\}\}$.

For $v\in V$ let $V_v = \span\{T^jv\mid j\ge0\}$. Clearly $V_v$ is invariant for $T$.

_Spectral mapping theorem_ If $p$ is a polynomial then $p(\sigma(T)) = \sigma(p(T))$.

__Exercise__. _If $T\colon V\to V$ and $T^m = 0$ for some $m$ then $\sigma(T) = \{0\}$_.

<details>
<summary>Solution</summary>
Using the spectral mapping theorem we have $\{0\} = \sigma(T^m) = \sigma(T)^m$.
If $0 = \lambda^m$ then $\lambda = 0$.
</details>

### Jordan Canonical Form

Suppose $T\colon V\to V$ is a linear operator on an $n$-dimensional
space $V$.  For $v\in V$ define its _order_, $o(v), to be the minimum
$m$ such that $v, Tv, \ldots T^mv$ are linearly dependent.  If $o(v)$
equals the dimension of $V$ then $v$ is a _cyclic vector_ for $T$
and $T^n v = \sum_{0\le j< n}a_j T^jv$ for some $a_j\in\RR$.
Using the basis $v$, $Tv$, \ldots, $T^{n-1}v$
gives a representation for $T$ as a matrix.


$T(\sum_j a_j T_j) = \sum_j a_jT^{j+1}$

 and $\sigma(T) = \{0\}$.
For any $v\in V$ the vectors $v$, $Tv$, \ldots, $T^n$ are linearly dependent
so $p(T)v = 0$ from some polynomial $p$.

Given $v_1,\ldots,v_n\in V$ define the _shift operator_ $J\colon V\to V$ 
by $Jv_i = v_{i+1}$, $1\le j < n$ and $Jv_n = \zero$.
