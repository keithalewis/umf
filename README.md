---
title: Unified Mathematical Finance
author: Keith A. Lewis
...

# Unified Mathematical Finance

Mathematical Finance provides a rigourous model for quanifying the
problems of how to move cash flows through time, how much does it cost,
and how risky is that.  The classical Black-Scholes/Merton approach
assumes optimal hedging strategies executed in "continuous" time. A model
more faithful to trading reality should allow for non-optimal strategies
and the fact that continuous time hedging is not possible.

The atoms of finance are _holdings_, an amount of some instrument and who owns it.
Holdings interact via _transactions_, a swap of holdings between a buyer and a seller on some date.

## Date/Time

A _date_, or _datetime_, is an absolute time. Universal Coordinated Time,
or UTC, can be used for this. The permuted acronym has an interesting history,
as do all matters involved with measuring dates and times.

The difference of two dates is a _time period_ between two dates.
An _epoch_ date can be used to convert between dates and times. The epoch corresponds to time 0
and the date is a time period offset from that.
It is common to work with time in years, although years is not a proper time period
since it may involve leap days. Likewise, using seconds has a similar problem because
of leap seconds.

## [Instrument](https://ifrscommunity.com/knowledge-base/financial-instruments-definitions/)

Instruments are contracts that provide ownership of a financial asset to the holder
and a financial liability of the instrument issuer.

The most fundamental instrument is cash in a particular currency.
Stocks provide equity in the issuing company. Bonds are a contractual right
to coupons and final principal repayment by the issuer.
A commodity is not an instrument, but a forward rate agreement to exchange cash
for the commodity at the termination date of the contract is.
These instruments are backed by tangible assets.
Convertible bonds, asset backed securities, and structured products are
hybrid intruments. Classical derivitive instruments are options, forwards, and futures.

A derivative contract specifies the cash flows between the buyer and the seller.
If a derivative is not traded in the market then there is a mathematical theory originally
developed by Black, Scholes, and Merton to approximate its _value_.
A sell-side trader can use that, plus vigorish, to quote prices.

There is a credit component to every intrument. Either party might default on their
contractual obligations. This can be modeled using _default time_ and _recovery_.

## Transaction

A _transaction_ is a _buyer_ and a _seller_ exchanging holding at a _transacton time_.
The transaction $\chi = (t;a, i, o; a', i', o')$
indicates the _buyer_ swapped the holding $(a, i, o)$
for the holding $(a', i', o')$
with the _seller_ at time $t$.
At _settlement_ $u > t$
the buyer holds $(a',i',o)$
and the seller holds $(a,i,o')$.
The _price_ of the transaction is $X = a/a'$ so
$\chi = (t;Xa', i, o; a', i', o')$.
Note $X = X(t; i, o; a',i',o')$ depends on the time executed,
the buyer instrument, and the amount of the seller instrument.
Prices are determined by the seller. The buyer decides when to exchange
holdings based on the seller’s price, among other considerations.

Owning an instrument entails _cash flows_. Stocks pay dividends or incur borrow costs when shorted.
Bonds pay coupons. Currencies do not have cash flows. Commodities may have storage costs.
Futures cash flows are the daily margin adjustents. The price of a futures is always zero.
Cash flows are added to holdings in proportion to the amount of the instrument.

Cash flows are transactions between the buyer and the issuer that are triggered
by contractual obligations instead of trading events. If issuer $o'$
pays cash flow $C$
in units of instrument $i$
at time $t$
then all holders of $(a, i', o)$
incur a transaction $(t;Ca, i, o; -Ca, i, o')$.

Given a _portfolio_ of holdings $\{(a_j, i_j, o_j)\}$
define the _net amount_ of asset $i$
held by entity $o$ to be
$$
	N(i, o) = \sum \{a_j\mid i_j = i, o_j = o\}.
$$
Transactions and cash flows change a set of holding over time.
If transaction $\chi = (t;a, i, o; a', i', o')$
settles at $u > t$ then the set of holdings at $u$ 
now includes $\{(-a, i, o), (a', i', o), (-a', i', o'), (a, i, o')\}$.
The holdings with negative signs are often netted with existing buyer and seller holdings.
This assumes the holdings $(a_0, i, o)$
and $(a_1, i, o)$
can be combined to the holding $(a_0 + a_1, i, o)$.
This is close to being true when $a_0 > 0$
and $a_1 > -a_0$, but that, and every, assumption should be made explicit.

To _mark-to-market_ a portfolio fix an instrument $i_0$ and posit
a set of prices $X(i_0,i)$ for converting each instrument.
The mark-to-market is
$$
	M(i_0) = \sum_{i,o} X(i_0, i) N(i,o).
$$
Typically $i_0$ is the native currency and it is assumed there is a large set
of foreign exchange liquidity providers willing to offer price $X(i_0, i)$ 
to any counterparty in any size for any instrument $i$. We assume
$X(i_0,i_0) = 1$ and the sum is over all instruments, including $i_0$.

The _profit-and-loss_ (P&L) per instrument and holder over the interval $[t, u]$ is
$N_u(i,o) - N_t(i,o)$. 

<!--
### Examples

...

## Discount

_Discount_ is the cost of moving 1 unit of some currency in the future
to time 0.
Let $D(u)$ be the price of a _zero coupon bond_ that pays 1 unit at time $u$.
It is not the case that zero coupon bonds of all maturities trade
but it is useful to construct a _discount curve_ $u\mapsto D(u)$
to approximate the price. Discount
can be expressed in terms of the _forward curve_ $f(t)$ defined by
$D(u) = \exp(-\int_0^u f(t)\,dt)$ or the _spot curve_ $r(t)$ defined
by $D(u) = \exp(-u r(u))$.

__Exercise__. _Show $f(t) = -d(\log D(t))/dt$ and $r(t) = -(\log D(t)/t)$_.

__Exercise__. _Show $r(t) = (1/t)\int_0^t f(s)\,ds$ and $f(t) = r(t) + tr'(t)$_.

A _fixed income instrument_ is a portfolio of zero coupon bonds
paying cash flows $c_k$ at times $u_k$. If the price of the bond is $p$ then
$p = \sum_k c_k D(u_k)$.
Given a set of fixed income instruments with prices $p_j$ and
cash flows $c_{jk}$ at times $u_{jk}$, $0\le k < n_j$. We wish to find a discount
curve that reprices each instrument
$$
	p_j = \sum_k c_{jk} D(u_{jk}), \text{ for all } j.
$$
This problem is highly underdetermined, but the _bootstrap_ method provides a unique solution.

## Bootstrap

Assume $u{jk}


## UNFILED

Vector space
	Linear transformation
	Dual space
	Frechet derivative

Measure
	$B(S)^* \cong ba(S)$
	Algebra of sets - partial information

Probability 
	Random variable
	Random variables
	Stochastic process
	Stochastic integral

$X_t = M_t - \sum_{s\le t}C_s D_s$.

TwoBitCoin

Send through Switzerland. Buy tax law from cantons.

https://bam.kalzumeus.com/archive/moving-money-internationally/
-->
