# salesTaxes-pb

_This code prints out the receipt details for some shopping baskets._

## Input 
The input data, contained in the text file _data.txt_, are organized in a table whose columns rapresent in order:
`product name` (i.e. `book`, `bottle_of_parfume`),
`product type` (the variable is 1 if `name` is book, food or medical product, 0 otherwise),
`price`,
`import variable` (it is 1 if the product is imported, 0 otherwise).

## Code
Given such input data, the program randomly selects three lines and these will be the inputs for the program.
Each product is the object of the `shop` structure:

```
struct shop
{
	string goods; // kind of goods 
	int type; // type=1 if good is food, book or medical product, 0 otherwise
	double price; // shelf price
	int import; // it is 1 if the object is imported, 0 otherwise
};
```

This object is input for the function `define_tax` that, depending on product characteristics, calculates 
the taxes to which it is subject. In the same function, the receipt details are printed.

## Output
The output contains:
* a row for each product with `name`, `price` and the string `(import)` if the the product is imported,
* the sum of applied taxes (`tax` in the code), 
* the total price (`total` in the code).

As requested, the amount of sales tax is rounded up to the nearest 0.05.

# Licenze
This work is licensed under the MIT License - see the [LICENSE.md](https://github.com/DomeCl/salesTaxes-pb/blob/master/LICENSE) file for details.

