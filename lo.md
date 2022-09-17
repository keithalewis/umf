---
title: Logistic Distribution
author: Keith A. Lewis
fleqn: true
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
\newcommand\Var{\operatorname{Var}}
\newcommand\Cov{\operatorname{Cov}}
\renewcommand\span{\operatorname{span}}
\newcommand\qed{$\square$}

Every positive random variable $F$ is parameterized by $F = fe^{-\kappa(s) + sX}$
where $f = E[F]$, $s^2 = \Var(\log F)$, $X$ is a random variable with mean 0, variance 1, and
$\kappa(s) = \log E[e^{sX}]$ is the cumulant of $X$.

The Black model of option pricing assumes $X$ is standard normal. We investigate
the case when $X$ has a _logistic_ distribution.

## Logistic Distribution

The logistic cumulative distribution function with parameter $\sigma$ is
$P(X\le x) = F(x) = 1/(1 + e^{-x/\sigma})$, $-\infty < x < \infty$
and has density function is $f(x) = e^{-x/\sigma}/\sigma(1 + e^{-x/\sigma})^2$.
By symmetry, it has mean 0. It is not trivial to show its variance is $\pi^2\sigma^2/3$
so $\sigma = \sqrt{3}/\pi$ implies variance 1.

Solving $q = F(x) = 1/(1 + e^{-x/\sigma})$ for $x$ gives the quantile function
$$
\begin{aligned}
	q &= F(x) = 1/(1 + e^{-x/\sigma}) \\
	(1 + e^{-x/\sigma}) &= 1/q \\
	e^{-x/\sigma} &= 1/q - 1 = (1 - q)/q \\
	e^{x/\sigma} &= q/(1 - q) \\
	x &= F^{-1}(q) = \sigma\log(q/(1 - q)) = \sigma (\log q - \log(1 - q)) \\
\end{aligned}
$$

Since $e^{x/\sigma} = q/(1 - q)$ and $dF(x) = dq$ 
we have the moment generating function is
$$
\begin{aligned}
	E[e^{sX}] &= \int_{-\infty}^\infty e^{sx} \,dF(x) \\
		&= \int_0^1 (q/(1-q))^{\sigma s}\,dq \\
		&= B(1 + \sigma s, 1 - \sigma s)\\
\end{aligned}
$$
where $B(\alpha,\beta) = \int_0^1 q^{\alpha - 1} (1 - q)^{\beta - 1}\,dq$ is the beta function
and we use $\alpha - 1 = \sigma s$ and $\beta - 1 = -\sigma s$.

The Gamma function $\Gamma(\alpha) = \int_0^\infty x^{\alpha-1}e^{-x}\,dx$ is
related to the Beta function by $B(\alpha, \beta) = \Gamma(\alpha)\Gamma(\beta)/\Gamma(\alpha + \beta)$.
Note $\Gamma(\alpha + 1) = \alpha\Gamma(\alpha)$, $\alpha > 0$.
[Euler's reflection formula](https://www.planetmath.org/EulerReflectionFormula)
for the Gamma function is $\Gamma(\alpha)\Gamma(1 - \alpha) = \pi/\sin(\pi\alpha)$.

__Exercise__. _Show $E[e^{sX}] = \Gamma(1 + \sigma s)\Gamma(1 - \sigma s) = \pi\sigma s/\sin \pi\sigma s$_.

The cumulant is $\kappa(s) = \log E[e^{sX}] = \log \pi\sigma s - \log\sin\pi\sigma s$.
Using $\Var(X) = \kappa''(0)$ a non-trivial calculation gives $\Var(X) = \pi^2\sigma^2/3$.

<!--
__Exercise__. _Show the cumulant $\kappa(s) = \log E[e^{sX}]
= \log\Gamma(1 + s/\sigma) + \log\Gamma(1 - s/\sigma)$_.

_Hint_. $\Gamma(n) = (n - 1)!$ if $n$ is a positive integer.

The derivative of the log of the Gamma function is psi $\psi(x) = \Gamma'(x)/\Gamma(x)$.
Its power series expansion at 1 is
$$
	\psi(1 + x) = -\gamma + \sum_{k=2}^\infty (-1)^k\zeta(k)x^{k - 1}
$$
where $\gamma$ is the Euler-Macheroni constant and the zeta function is
$\zeta(s) = \sum_{n=1}^\infty 1/n^s$.
-->

## [Incomplete Beta Function](https://dlmf.nist.gov/8.17)

Share measure for the logistic is
$$
\begin{aligned}
	P^s(X \le x) &= E[e^{-\kappa(s) + sX} 1(X\le x)] \\
		&= \int_{-\infty}^x e^{-\kappa(s) + sz}\,dF(z) \\
		&= e^{-\kappa(s)}\int_0^{F(x)} (q/(1-q))^{s/\alpha}\,dq \\
		&= B_{F(x)}(1 + \sigma s, 1 - \sigma s)/B(1 + \sigma s, 1 - \sigma s)\\
\end{aligned}
$$
where $B_u(\alpha, \beta) = \int_0^u q^{\alpha - 1} (1 - q)^{\beta - 1}\,dq$ is the incomplete beta function.

This can be calculated using the hypergeometic function
$$
	{}_2F_1(a, b; c; u) = \sum_{n=0}^\infty \frac{(a)_n(b)_n}{(c)_n} \frac{u^n}{n!}
$$
where $(q)_n$ is the rising Pockhammer symbol defined by
$(q)_0 = 1$ and $(q)_n = q(q + 1)\cdots(q + n - 1)$ if $n > 0$.

We have
$$
	B_u(\alpha, \beta) = \frac{x^\alpha}{\alpha}{}_2F_1(\alpha, 1 - \beta; \alpha + 1; u)
$$
so
$$
	P^s(X \le x) = \frac{F(x)^{1 + \sigma s}}{(1 + \sigma s)B(1 + \sigma s, 1 - \sigma s)}
		{}_2F_1(1 + \sigma s, \sigma s; 2 + \sigma s; F(x))
$$
