# Order Book

## Market

The _market_ consists of _instruments_ that are _issued_,
_traded_/_exchanged_ by market participants, _expire_ or _mature_,
and the legal frameworks regulating activities.
It is so large and complicated that it is beyond human limits
to fully comprehened, but that doesn't mean we can't try.
What follows is an attempt to specify a rigourous mathematical
theory to help reason about this.

### Intruments

Stocks, bonds, currencies, commodities, options, and futures are examples of _instruments_.
There are many more.
Instruments have _prices_ and may have _cash flows_ associtated
with holding them. Price is usually quoted in terms of
a currency.
Dividends are cash flows associated with
holding a stock. The amount of the cash flow is proportional
to the number of shares held.
Coupons are cash flows associated with a bond.
Currencies do not have cash flows.
Commodities may have storage costs that are negative cash flows.
A _European option_ has a single cash flow at _expiration_ that
is a function of an _underlying_ instrument. Such instruments
are called _derivatives_.
The price of a futures contract is always zero.
It has daily cash flows equal to the change in the _quote_


If Ford stock is quoted as 8 dollars per share then $a$
shares can be _bought_ ($a > 0$) or _sold_ ($a < 0)
for $8a$ dollars.

A _holding_ is an _instrument_, _amount_, and _legal entity_.
The entity owns the given amount of the instrument and has
the right to exchange it for other holdings in a _transaction_.
_Sellers_ provide _buyers_ with information about what transactions
they are willing to do.  Buyers decide what transactions to execute.
Buyers and sellers can either _buy_ (amount is positive) or _sell_
(amount is negative) holdings.

A _portfolio_ is a collection of holdings for a particular entity.
It changes over time due to transactions and cash flows associated
with the intruments being held.

Given a set of holdings $\mathcal{H} = \{(i_j, a_j, e_j)\}$

An _order books_ is a collection of _limit orders_. A limit order
is determined by an _instrument_, _amount_, _level_, and entity. 
