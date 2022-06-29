---
title: Stochastic Integration
author: Keith A. Lewis
...

\newcommand\RR{\boldsymbol{R}}
\newcommand\CC{\boldsymbol{C}}
\newcommand\FF{\boldsymbol{F}}
\newcommand\NN{\boldsymbol{N}}
\renewcommand\AA{\mathcal{A}}
\newcommand\PP{\mathcal{P}}
\newcommand\zero{\boldsymbol{0}}
\renewcommand\ker{\operatorname{ker}}
\newcommand\ran{\operatorname{ran}}
\renewcommand\span{\operatorname{span}}
\newcommand\qed{$\square$}

The widest class of stochastic processes for which a stochastic integral
with nice properties can be defined are semi-martingales
that are (almost surely) right-continuous and have left limits.
The Ito integral is a special case when the process is Brownian motion.
By coincidence, the integral is appropriate for
calculating the profit and loss of trading strategies.

## Riemann-Stieltjes

Before defining stochasic integration we review Riemann integrals and
the generalization of those due to Stieltjes.

If $f\colon [a,b]\to\RR$ is a continuous function then the area bounded
by its graph can be approximated by choosing a partition
$a = x_0 < \cdots < x_n = b$ of $[a,b]$ and calculating
$$
	\sum_{0\le i < n} f(x_i^*)\,(x_{i + 1} - x_i) = \sum_{0\le i < n} f(x_i^*)\,\Delta x_i
$$
where $x_i \le x_i^* \le x_{i + 1}$. Let $[x_i]$ denote the partition
and $\|[x_i]\| = \max_i \Delta x_i$. 
We say $[x_i']$ is a _refinement_ of $[x_i]$ if $\{x_i\}\subseteq\{x_i'\}$.

__Exercise__. _Show $\|[x_i']\| \le \|[x_i]\|$ if $[x_i']$ is a _refinement_ of $[x_i]$_.

We use the notation $\lim_{\|[x_i]\|\to 0} I([x_i]) = I$ to indicate given
$\delta > 0$ and $\epsilon > 0$ there exists a partion $[x_i]$
with $\|[x_i]\| < \delta$ and $|I([x_i']) - I| < \epsilon$ for
any refinement $[x_i']$ of $[x_i]$.

The Riemann integral is defined by
$$
	\int_a^b f(x)\,dx = \lim_{\|[x_i]\|\to 0} \sum_{0\le i < n} f(x_i^*)\,\Delta x_i.
$$
It can be shown the limit exists and is unique no matter the choice of $x_i^*\in[x_i, x_{i+1}]$.

Stieltjes showed the integral can be generalized for any monontonic function $F\colon[a,b]\to\RR$
$$
	\int_a^b f(x)\,dF(x) = \lim_{\|[x_i]\|\to 0} \sum_{0\le i < n} f(x_i^*)\,(F(x_{i+1} - F(x_i)).
$$
The Riemann integral is the special case $F(x) = x$.

The _indicator function_ $1_A(x) = 1$ if $x\in A$ and $1_A(x) = 0$ if $x\not\in A$.
Let $H_c(x) = 1_{[c, \infty)}(x)$ be the Heavyside step function at $c$. 

__Exercise__. _Show $\int_a^b f(x)\,dH_c(x) = f(c)$ if $a < c < b$_.

_Hint_: Only one term in $\sum_i f(x_i^*)\,\Delta H_c(x)$ is non-zero.

Although $dH_c$ is not defined, it is sometimes referred to as a
_point mass_ or _delta function_ at $c$.

The _total variation_ of a function $f\colon [a,b]\to\RR$ is
$$
	V(f;a,b) = \sup_{a = x_0 < x_1 < \cdots < x_n = b} \sum_{0\le i < n} |f(x_{i+1}) - f(x_i)|
$$
__Exercise__. _If $f$ is monotonic then $V(f;a,b) = |f(b) - f(a)|$_.
<details>
<summary>Solution</summary>
If $f$ is non-decreasing then $\sum_{0\le i < n} |f(x_{i+1}) - f(x_i)| = f(b) - f(a)\ge0$.
If $f$ in non-increasing then $-f$ is non-decreasing.
</details>

__Exercise__. _If the derivative of $f$ is continuous, show $V(f;a,b) = \int_a^b |f'(x)|\,dx$_.

__Exercise__. (Jordan decomposition) _Show every function of bounded variation is the sum of 
a non-decreasing function and a non-increasing function_.

_Hint_: Let $f^+ = \sup_{a = x_0 < x_1 < \cdots < x_n = b} \sum_{0\le i < n} \max\{f(x_{i+1}) - f(x_i),0\}$
and $f^- = \sup_{a = x_0 < x_1 < \cdots < x_n = b} \sum_{0\le i < n} \min\{f(x_{i+1}) - f(x_i),0\}$.
Use $\max\{x,0\} + \min\{x,0\} = x$.


This shows we can define $\int_a^b f(x)\,dF(x)$ when $F$ has bounded variation.

__Exercise__. _If $F'$ exists and is continuous the $\int_a^b f(x)\,dF(x)
= \int_a^b f(x)F'(x)\,dx$_.

The _quadratic variation_ of a function $f\colon [a,b]\to\RR$ is
$$
	\omega(f;a,b) = \sup_{a = x_0 < x_1 < \cdots < x_n = b} \sum_{0\le i < n} (f(x_{i+1}) - f(x_i))^2
$$

__Exercise__. _Show $\lim_{\|[x_j]\|\to 0} \omega(f,[x_i])/V(f,[x_i]) = 0$ if $f$ is continuous_.

<details>
<summary>Solution</summary>
If $|f(x_{i+1} - x_i)| < \epsilon$ then
$(f(x_{i+1} - x_i)^2/|f(x_{i+1} - x_i)| < \epsilon$.
</details>


## Stochastic Integration

Assume $(X_t)_{t\ge0}$ is a stochastic process on the sample space $\Omega$
with measure $P$ and each $X_t$ is $\AA_t$ measurable, $t\in T$, where
$\AA_t$ is a (sigma) algebra on $\Omega$.

A process $(X_t)$ is _c&agrave;dl&agrave;g_ (<b>c</b>ontinue __&agrave;__ la
<b>d</b>roite, <b>l</b>imite __&agrave;__ la <b>g</b>auche) if the
right limit $\lim_{u\searrow t} X_u = X_t$ almost surely and the left
limit $\lim_{s\nearrow t}X_s = X_{t-}$ exists almost surely.
It is _c&agrave;gl&agrave;d_ if $\lim_{s\nearrow t}X_s = X_{t}$ almost surely
and $\lim_{u\searrow t} X_u = X_{t+}$ exists almost surely.

C&agrave;dl&agrave;g processes are an appropriate model of stock prices.
The price shown on a trading screen might not be the price at which the trade is executed.
Consider the trading strategy of buying one share at $a$ and selling it at $b > a$.
The _position_ at time $t$ is $1_{(a, b]}(t)$.
Even though the share is purchased at time $a$ the position is 0.
It takes some time for the trade to settle before you own it.

__Exercise__. _Show $1_{(a, b]}$ is c&agrave;gl&agrave;d_.

The _profit and loss_ of the strategy at time $t$ is $X_{\min\{t,b\}} - X_{\min\{t,a\}}$.
If $t < a$ then you hold no shares. If $a < t < b$ then liquidating at that time
whould give a profit of $X_t - X_a$. If $t > b$ then the profit from the now
terminated strategy is $X_b - X_a$.

This motivates the definition of the _stochastic integral_
$$
	\int_0^t \Xi_s\,dX_s = X_{t\wedge b} - X_{t\wedge a}
$$
when $\Xi_t = 1_{(a,b]}(t)$. Of course the number of shares can depend on the
information available at time $a$ so we can generalize this to integrands
of the form $\Xi_t = \xi 1_{(a,b]}(t)$ for any $\AA_a$ measurable $\xi$
$$
	\int_0^t \Xi_s\,dX_s = \xi(X_{t\wedge b} - X_{t\wedge a}).
$$
A technical detail is that we can't effectively trade on information that
becomes avaialable exactly at time $a$.
Define $\AA_{a-} = \cup_{t < a}\AA_t$ and require $\xi$ to be $\AA_{a-}$ measurable.

__Exercise__. _If $(\Xi_t)$ has a left limit at $u$ then $\Xi_u$ is $\AA_{u-}$ measurable_.

Processes of the form $\Xi_t = \xi 1_{(a,b]}$ where $\xi$ is $\AA_{a-}$ measurable
are called _elementary_. A finite sum of elementary processes is _simple_.
The definition of stochastic integration can be extended to simple integrands
by linearity. The class of simple functions is sufficent for modeling
trading strategies since only a finite number of transactions can be executed.

We say a stochastic process $(\Xi_t)_{t\in T}$ is _predictable_ if
$X_t$ is $\AA_{t-}$ measurable for all $t\in T$.

We say $(X_t)$ is _integrable_ if $E[|X_t|]$ is finite for all $t$.

A stochastic process has bounded variation if $\omega\to X_t(\omega)$ is bounded variation
with probability 1.

A stochastic process is a _martingale_ if $X_t = E[X_u\mid\AA_t]$ for $u\ge t$, where
$EX\mid\AA]$ is the conditional expectation of the random variable $X$ with respect to
the algebra $\AA$.

__Definition__. _$Y = E[X\mid\AA]$ if and only if $Y$ is $\AA$ measurable and
$\int_A Y\,dP = \int_A X\,dP$ for all $A\in\AA$_.

__Exercise__. _$Y = E[X\mid\AA]$ if and only if $Y(P|_\AA) = (XP)|_\AA$_.

_Hint_: We use $P|_\AA$ to indicate the measure $P$ restricted to the algebra $\AA$.
If $X$ is an integrable function then $XP$ defines a measure by
$(XP)(A) = \int_A X\,dP$ for $A\in\AA$.

