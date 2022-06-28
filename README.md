# Unified Mathematical Finance

How to move cash flows through time.

How much does it cost.

How risky is it.

Holding: amount, instrument, owner

Transaction: swap holdings on some date.

## Time

Date.

Time is a period between two dates. An _epoch_ is a date
used to uniquely convert times to dates.

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

Cost of moving 1 unit in the future to today.

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
