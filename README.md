---
title: Unified Mathematical Finance
author: Keith A. Lewis
...

# Unified Mathematical Finance

How to move cash flows through time. How much does it cost. How risky is it.

Holding: amount, instrument, owner

Transaction: swap holdings between a buyer and a seller on some date.

## Date/Time

A _date_, or _datetime_, is an absolute time. Universal Coordinated Time,
or UTC, can be used for that. The permuted acronym has an interesting history,
as do all things involved with measuring dates and times.

The difference of two dates is a _time period_ between two dates.
An _epoch_ date can be used to convert between dates and times. The epoch corresponds to time 0.
It is common to work with time in years, although years is not a proper time period
since it may involve leap days. Likewise, seconds has a similar problem because
of leap seconds.

## Instrument

Fundamental: Stock, bond, currency, commodity.
Backed by tangible assets. 

Hybrid: convertible bond, structured product, asset backed security

Derivative: option, forward, futures

## Transaction

Instrument transactions involve _price_.
The transaction $\chi = (t;a,i,o;a',i',o')$ indicates at time $t$
_buyer_ $o$ swapped the holding $(a,i,o)$ for the holding $(a',i',o')$ with _seller_ $o'$.
At _settlement_ $u > t$
the buyer hold $(a',i',o)$ and the seller holds $(a,i,o')$.
The _price_ of the transaction is $X = a'/a$.

Owning an instrument involves _cash flows_. Stocks pay dividends or incur borrow costs when shorted.
Bonds pay coupons. Currencies do not have cash flows. Commodities may have storage costs.
Futures cash flows are the daily margin adjustents, and their price is always zero.

Derivatives are a contract that specify the cash flows between the buyer and the seller.
If a derivative is not traded in the market then there is a mathematical theory originally
developed by Black, Scholes, and Merton for _value_.

## Discount

The _discount_ is the cost of moving 1 unit of some currency in the future
to an epoch/today/time 0. The simplest case is a _zero coupon bond_ that pays 1 unit at time $u$.
If it is traded in the market, let $D(u)$ be the price of buying that.

A _fixed income instrument_ is a portfolio of zero coupon bonds
paying $c_i$ at times $u_i$.



The _fixed income market_ provides prices of bonds having fixed future cash flows.
A bond pays cash flows $c_i$ at times $u_i$ and has market price $p_i$.

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
