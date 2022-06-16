---
title: Linear Algebra
...

\newcommand\RR{\boldsymbol{R}}
\newcommand\CC{\boldsymbol{C}}
\newcommand\FF{\boldsymbol{F}}
\newcommand\NN{\boldsymbol{N}}
\newcommand\zero{\boldsymbol{0}}
\renewcommand\ker{\operatorname{ker}}
\newcommand\ran{\operatorname{ran}}
\renewcommand\span{\operatorname{span}}
\newcommand\qed{$\square$}

Linear algebra is the study of linear structures and functions that
preserve this structure.  Vector spaces are a mathematical sweet
spot. They are completely characterized by their dimension.

## Vector Space

A _vector space_ over a _field_ $\FF$ is set $V$ with
a binary operation $V\times V\to V$, $(v,w)\mapsto v + w$, and
a scalar product $\FF\times V\to V$, $(a,v)\mapsto av$, satisfying the distributive law.
The binary addition is _commutative_ ($v + w = w + v$),
_associative_ ($(u + v) + w = u + (w + v)$), has an _identity element_
$\zero$ ($v + \zero = v$), and each element has an inverse ($v + (-v) = \zero$).
The scalar product satisfies the _distributive laws_
$a(v + w) = av + aw$, $(a + b)v = av + bv$, $(ab)v = a(bv)$, $a,b\in\FF$, $v,w\in V$.
We also require $1v = v$ and $av = va$ for $a\in\FF$ and $v\in V$.

__Exercise__. _If $v + z = v$ for all $v\in V$ then $z = \zero$_.

This shows the additive identity is unique.

<details>
<summary>Solution</summary>
Taking $v = \zero$, $z = \zero + z = \zero$.
</details>

__Exercise__. _If $v + v = v$ then $v = \zero$_.

_Hint_: $v + (-v) = \zero$.

__Exercise__. _Show $0v = \zero$,
$a\zero = \zero$,
and $(-1)v = -v$, $a\in\FF$, $v\in V$_.

<details>
<summary>Solution</summary>
Note $0v + 0v = (0 + 0)v = 0v$ so $0v = \zero$.
If $a\not=0$ then for any $v\in V$ we have 
$v + a\zero = aa^{-1}v + a\zero = a(a^{-1}v + \zero) = aa^{-1}v = v$ so $a\zero = \zero$
since the identity is unique.
Since $v + (-1)v = 1v + (-1)v = (1 + (-1))v) = 0v = \zore$ we have $(-1)v = -v$.
</details>

If $S$ is any set then the set of all functions from $S$ to
$\FF$, $\FF^S = \{v\colon S\to\FF\}$, is a vector space.
The addition is defined pointwise
$$
	(v + w)(s) = v(s) + w(s)\text{ for } v, w\in\FF^S
$$ 
as is the scalar product 
$$
	(av)(s) = av(s)\text{ for } a\in\FF, v\in\FF^S.
$$

The additive identity, $\zero$, is the function $\zero(s) = 0$ for all $s\in S$.

__Exercise__. _Show $\FF^S$ is a vector space_.

We will see later that every vector space has this form. The cardinality
of $S$ is the _dimension_ of the vector space.

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

_Hint_: $\RR$ is a abelian group under addition.

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
$\RR^n = \{(x_1,\ldots,x_n)\mid x_i\in\RR, 1\le i\le n\}$,
where $\RR$ is the real numbers.
If $S = \{1,\ldots,n\}$ and $x\in\RR^S$ then $x(i) = x_i$
provides a correspondance between $\RR^{\{1,\ldots,n\}}$ and $\RR^n$.
The _Kronecker delta_ is $\delta_{ij} = 1$ if $i = j$ and
$\delta_{ij} = 0$ if $i \not= j$. The _standard basis_ in $\RR^n$
is $\{e_j\}_{1\le j\le n}\subset\RR^n$ where $(e_j)_i = \delta_{ij}$, $1\le i\le n$.

__Exercise__. _Show every vector $x = (x_1,\ldots,x_n)\in\RR^n$ can be written
using the standard basis as $x = \sum_j x_j e_j$_.

In what follows we will use the field $\CC$ of _complex numbers_ to make things simpler.

???Use F and introduce C when needed

## Subspace

A subset $W\subseteq V$ is a _subspace_ of $V$ if $W$ is also a vector space.
Clearly $\{\zero\}$ is the smallest subspace and $V$ is the largest subspace of $V$.

__Exercise__. _If $v\in V$ then $\CC v = \{av\mid a\in\CC\}$ is a subspace_.

Given any set $S\subset V$ define $\span S$ to be the smallest
subspace containing $S$.

__Exercise__. _If $S\subseteq V$ then
$\span S = \{\sum_{s\in S_0} a_s s\mid a_s\in\CC, S_0\subseteq S \text{ finite }\}$_.

We need $S_0$ to be finite for the sum to be defined when $S$ is infinite.

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
$u,v\in V$, and $a\in\CC$.

__Exercise__. _Show $T(au + v) = aTu + v$, $a\in\CC$, $u,v\in V$ implies $T$ is a linear operator_.

The values of a linear transformation on a basis determine the linear transformation.
If $\{v_i\}$ is a basis of $V$ then for every $v\in V$ there exist unique $x_i\in\CC$
with $v = \sum_i x_i v_i$ hence $Tv = \sum_i x_i Tv_i$.

If $\{w_j\}$ is a basis of $W$ then $Tv_i = \sum_j t_{ij }w_j$
for some $t_{ij}\in\CC$ so $T$ is represented by a matrix $(t_{ij})$
given bases of $V$ and $W$.

__Exercise__. _If $S\colon U\to V$ and
$T\colon V\to W$ are linear transformations represented by $(s_{ij})$ and $(t_{jk})$
respectively, then $TS\colon U\to W$ is represented by
$(\sum_j s_{ij} t_{jk})$_.

Matrix multiplication is composition of linear operators.

<details>
<summary>Solution</summary>
Let $\{u_i\}$ be a basis of $U$, $\{v_j\}$ be a basis of $V$, and $\{w_k\}$ be a basis of $W$.
We have
$$
(TS)u_i = T(\sum_j s_{ij} v_j) 
	= \sum_j s_{ij} Tv_j
	= \sum_j s_{ij} \sum_k t_{jk} w_k 
	= \sum_k (\sum_j s_{ij} t_{jk}) w_k. 
$$
</details>
Note how working in terms of a basis can be tedious.

If a linear operator $T\colon V\to W$ is one-to-one and onto then $T$ is an _isomorphism_.
_One-to-one_ means $Tu = Tv$ implies $u = v$ and _onto_ means for
every $w\in W$ there exists $v\in V$ with $Tv = w$.
The inverse of such an operator is defined by $T^{-1}w = v$ if and only if $Tv = w$,
just as for any function.
We say $V$ and $W$ are isomorphic and write $V\cong W$.
Isomorphism is an _equivalence relation_ on vector spaces.

__Exercise__. _Show $T^{-1}$ is linear_.

__Exercise__. _Show $V\cong V$, $V\cong W$ implies $W\cong V$,
and $U\cong V$, $V\cong W$ imply $U\cong W$_.

<details>
<summary>Solution</summary>
The identity function $I\colon V\to V$ is an isomorphism. If $T\colon V\to W$
is an isomorphism then so is $T^{-1}\colon W\to V$. If $S\colon U\to V$ and
$T\colon V\to W$ are isomorphisms then so is the composition
$TS\colon U\to W$.
</details>

The fundamental theorem of linear algebra is that two vector spaces are
isomorphic if and only if they have the same dimension.
The non-trivial proof of this is omitted.

Vector spaces are classified up to isomorphism by their dimension.

### Invariant Subspace

If $T\colon V\to V$ is a linear operator and $U$ is a subspace of $V$
then it is _invariant_ under $T$ if $TU\subseteq U$.

The set of all linear operators from a vector space $V$ 
to a vector space $W$, $\mathcal{L}(V,W)$, is also a vector space. The addition is defined by
$(S + T)v = Sv + Tv$, $S,T\in\mathcal{L}(V,W)$, $v\in V$ and scalar multiplication
by $(aT)v = a(Tv)$, $a\in\CC$.

__Exercise__. _Show  $\mathcal{L}(V,W)$ is a vector space_.

The _kernel_ of a linear transformation $T\colon V\to W$ 
is $\ker T = \{v\in V\mid Tv = 0\}$ and
the _range_ is $\ran T = \{Tv\mid v\in V\} \subseteq W$.

__Exercise__. _If $T\colon V\to W$ is a linear operator show the kernel is a subspace of $V$
and the range is a subspace of $W$_.

__Exercise__. _Show $\ker T = \{\zero\}$ implies $T$ is one-to-one_.

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
$T\colon V\to \CC^n$ by $Tv_i = e_i$ where $\{e_i\}$ is the standard basis of $\CC^n$.
By linearity $T(\sum_i a_i v_i) = \sum_i a_i e_i = (a_1,\ldots,a_n)\in\CC^n$.

__Exercise__ _Show $T$ is one-to-one and onto_.

_Hint_: _Onto_ means $\ran T = \CC^n$.

### Eigenvectors/values

If $T\colon V\to V$ is a linear operator and $\CC v$ is invariant under $T$
for some $v\not=\zero$ then
$v$ is an _eigenvector_ of $T$. The number $\lambda\in\CC$ with $Tv = \lambda v$
is the _eigenvalue_ corresponding to $v$.
Note if $Tv = \lambda v$ then $v\in\ker T - \lambda I\neq \{0\}$
and so $T - \lambda I$ is not invertible.

__Exercise__. _If $v$ and $w$ are eigenvectors with eigenvalue $\lambda$
then so is $v + w$_.

_Hint_: $\ker T - \lambda I$ is a subspace.

The _spectrum_ of an operator is the set $\sigma(T) 
= \{\lambda\in\CC\mid T - \lambda I\text{ is not invertable}\}$.
In finite dimensions it is equal to the set of eigenvaluse.

If $V = \CC^{\NN}$ where $\NN = \{0, 1, 2, \ldots\}$ are the natural numbers
define the _forward shift operator_ 
$S\colon V\to V$ by $S(v_0, v_1, v_2, \ldots) = (0, v_0, v_1, \ldots)$.

__Exercise__. _If $Sv = \lambda v$ then $v = \zero$_.

<details>
<summary>Solution</summary>
Note $S$ is one-to-one so $Sv = 0$ implies $v = 0$ and we can assume $\lambda\not=0$.
If $Sv = \lambda v$ then $(0, v_0, v_1,\dots) = (\lambda v_0, \lambda v_1, \lambda v_2,\ldots)$.
This implies $0 = \lambda v_0$ so $v_0 = 0$. Likewise $0 = v_0 = \lambda v_1$ so $v_1 = 0$.
By induction $v_j = 0$ for all $j$ so $v = \zero$.
</details>

This shows $S$ has no eigenvectors.

__Exercise__. _Show $\sigma(S) = \{\lambda\in\CC\mid |\lambda| \le 1\}$_.

_Hint_: If $|\lambda| > 1$ then $(\lambda I - S)^{-1} = I/\lambda + S/\lambda^2 + S^2/\lambda^3 + \cdots$.

We can also define the shift operator $J = J^n$ on $\CC^n$
by $J(x_1,\ldots,x_n) = (0, x_1,\ldots,x_{n-1})$.

__Exercise__. _Show $e_n$ is the only eigenvector and it has eigenvalue $0$_.

Note $J^2(x_1,\ldots,x_n) = (0, 0, x_1,\ldots,x_{n-2})$ has eigenvectors $e_{n-1}$ and $e_n$.
Likewise, $J^k$ has eigenvectors $e_{n-k+1},\ldots,e_n$, $1\le k\le n$.
Clearly $J^n = \zero$, the zero operator.

It is not hard to show $\sigma(J) = 0$ but we can use the _spectal mapping theorem_
to give a simple proof. If $p$ is a polynomial and $T\colon V\to V$ is a linear
operator then $p(T)\colon V\to V$ can be defined.

__Theorem__. (Spectral mapping theorem) _If $p$ is a polynomial then $p(\sigma(T)) = \sigma(p(T))$_.

_Proof_: For any $\lambda\in\CC$ $p(z) - p(\lambda) = (z - \lambda)q(z)$ for some
polynomial $q$. If $\lambda\in\sigma(T)$ then $P(T) - p(\lambda)I = (T - \lambda I)q(T)$.

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
and $T^n v = \sum_{0\le j< n}a_j T^jv$ for some $a_j\in\CC$.
Using the basis $v$, $Tv$, \ldots, $T^{n-1}v$
gives a representation for $T$ as a matrix.


$T(\sum_j a_j T_j) = \sum_j a_jT^{j+1}$

 and $\sigma(T) = \{0\}$.
For any $v\in V$ the vectors $v$, $Tv$, \ldots, $T^n$ are linearly dependent
so $p(T)v = 0$ from some polynomial $p$.

Given $v_1,\ldots,v_n\in V$ define the _shift operator_ $J\colon V\to V$ 
by $Jv_i = v_{i+1}$, $1\le j < n$ and $Jv_n = \zero$.
