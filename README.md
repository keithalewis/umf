---
title: Unified Mathematical Finance
author: Keith A. Lewis
...

# Unified Mathematical Finance

When $a \ne 0$, there are two solutions to $(ax^2 + bx + c = 0)$ and they are 
$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a} $$

Mathematical Finance provides a rigourous model for quanifying the problems of
how to move cash flows through time, how much does it cost, and how risky is that.
The classical Black-Scholes/Merton approach assumes optimal hedging strategies
executed in "continuous" time. A complete model should allow for the non-optimal
strategies that exist in the real world and the fact that continuous time
hedging is not possible.

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
Prices are determined by the seller. The buyer decides when to exchange
holdings based on the seller’s price, among other considerations.

Owning an instrument entails _cash flows_. Stocks pay dividends or incur borrow costs when shorted.
Bonds pay coupons. Currencies do not have cash flows. Commodities may have storage costs.
Futures cash flows are the daily margin adjustents. The price of a futures is always zero.
Cash flows are added to holdings in proportion to the amount of the instrument.

Given a set of holdings $\{(a_j, i_j, o_j)\}$
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

Cash flows are transactions between the buyer and the issuer that are triggered
by contractual obligations instead of trading events. If issuer $o'$
pays cash flow $C$
in units of instrument $i$
at time $t$
then all holders of $(a, i', o)$
incur a transaction $(t;Ca, i, o; -Ca, i, o')$.

### Examples

...

## Discount

The _discount_ is the cost of moving 1 unit of some currency in the future
to time 0. The simplest case is a _zero coupon bond_ that pays 1 unit at time $u$.
Let $D(u)$ be the price of buying that.

A _fixed income instrument_ is a portfolio of zero coupon bonds
paying cash flows $c_i$ at times $u_i$. If the price of the bond is $p$ then
$p = \sum_i c_i D(u_i)$.


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
