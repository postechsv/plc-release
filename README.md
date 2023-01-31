STbmc
==========
STbmc is a bounded LTL model checking tool for PLC ST language.
It checks whether the given PLC software in ST language satisfies an LTL property.
It provides an input language to easily specify input sequences and LTL properties over *multiple scan cycles*.
The input language is introduced in the following section.
You can find more detail [here](https://dl.acm.org/doi/abs/10.1145/3563822.3568016).



PLC requirement specification
==========
There are three sections of requirement specifications: `INPUT`, `STEP`, and `CONDITION`.

* `INPUT` section specifies input patterns given to the PLC programs.
An input pattern decides the sequence of values given to specific variables in each cycle.
The sequence of values can be either concrete (e.g. 1, 5, 7, ...) or symbolic (unspecified).

Each line takes the following form:

```[Program name] :: [Identifier] |-> [input pattern]```

*input pattern* can be a sequence of symbolic values (specified as `??`)
or comma-separated concrete values. If there is a repeated subsequence of concrete values,
it can be specified using `repeat` function. (e.g. `repeat(1, 3)` specifies 1, 3, 1, 3, 1, ...)


* `STEP` section takes a single natural number to specify the LTL model checking bound.
The bound is in the number of PLC scan cycles, not the number of semantic transitions.

* `CONDITION` section specifies an LTL property of the output sequence 
when the PLC software is given an input sequence specified in `INPUT` section.
Atomic propositions are Boolean expressions over state variables,
where variables in the input sequence can also be referred using `I[_]` operator.
For example, `I[PRGORAM1 :: y] <= PROGRAM1 :: y` means variable `y` of program `PROGRAM1`
is greater after the execution than before the execution.
The tool supports usual logical and temporal operators, such
as AND, OR, NOT, ==> (implication), GLOBALLY, FINALLY, NEXT,
and UNTIL.


How to install
==========
1. clone this repository
2. set $PLCSCRIPTPATH to `scripts/` folder 

Directory structure
==========
* `apps/` contains example PLC software (trafficLight) and example requirement specifications (.req files).
* `benchmark/` contains benchmark models for STbmc and PLCverif for performance comparison.
* `libs/` contains standard PLC function block definitions.
* `scripts/` contains files for tool implementation including parsing, compiling, reporting counterexample, etc.
* `semantics/` is the semantic definition of PLC ST.
  - `builtinfunctions/` contains the definition of standard functions
  - `concreteANDsymbolic` contains the concrete and symbolic definition of PLC semantics.
  - `core` contains the core definition of PLC.
  - `interpreter` contains interpreters for different versions of PLC ST (concrete/symbolic/mixed)
  - `syntax` contains the syntactic definition of PLC ST.
* `stbmc.sh` is the shell script to execute STbmc.

How to run
==========
* In the home directory of plc-release, type in the following command:
```./stbmc.sh [PLC project directory] [requirement file]```
* `apps/trafficLight` is provided as an example PLC project 
   and `caseStudy-1.req`, `caseStudy-2.req` as requirement specifications.
   These examples are explained in section 6 of [this paper](https://dl.acm.org/doi/abs/10.1145/3563822.3568016).
* To verify the requirement `caseStudy-1.req`, use the following command:
```./stbmc.sh apps/trafficLight apps/caseStudy-1.req```




