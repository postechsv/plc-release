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
*Prerequisite*
1. Python 3.8.5
2. pip3 22.0
3 . Python module antlr4-python3-runtime version 4.9

*Installation*
1. Install antlr4-python3-runtime version 4.9 if you don't already have it:

  ```python3 -m pip install antlr4-python3-runtime==4.9```

2. clone this repository
3. set `$PLCSCRIPTPATH` to `scripts/` folder
4. set `$MAUDE_BIN` to `maude-se/` folder

Directory structure
==========
* `apps/` contains example PLC software (trafficLight) and example requirement specifications (.req files).
* `benchmark/` contains benchmark models for STbmc and PLCverif for performance comparison.
* `libs/` contains standard PLC function block definitions.
* `maude-se/` contains the `maude-se-yices2` tool and its built-in library.
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
*General instruction*
* In the home directory of plc-release, type in the following command:
```./stbmc.sh [PLC project directory] [requirement file]```
* `apps/trafficLight`, `apps/trafficLight-repaired` is provided as example PLC projects 
   and `sim.req`, `caseStudy-1.req` (r1.req in the paper), `caseStudy-2.req` (r2.req in the paper) as requirement specifications.
   These examples are explained in section 6 of [this paper](https://dl.acm.org/doi/abs/10.1145/3563822.3568016).
* To verify the requirement `caseStudy-1.req`, use the following command:

```
>./stbmc.sh apps/trafficLight apps/caseStudy-1.req
Compiling trafficLight.st ...
Compile Succeeded
analyzing trafficLight using caseStudy-1
test succeeded
Result will be located in [top-directory]/apps
running time :  1622.1659774780273 sec
```

*Benchmark - STbmc*

Benchmark PLC models for STbmc are stored in `benchmark/straton`,
There are 18 benchmark models named `benchmark[index]` where `[index]` is 1, 2, 3, ..., 18.
Requirement specifications for each model are stored in `benchmark/stverif/benchmark[index]`.
There are 1-5 requirement specifications for each model, each named `req[index]_INF.req`.

To run the first benchmark model with the first requirement file, use the following command in the top directory:

```
>./stverif.sh ../benchmark/straton/benchmark1/benchmark1 benchmark/stverif/benchmark1/req1_INF.req
```

*Benchmark - PLCverif*

PLCverif executable file `plcverif-cli` is located in `benchmark/plcverif/cmd`.
Under `benchmark/plcverif/cmd/` folder, `workspace` and `workspace2` are respectively set up for nuXmv and CBMC backend engine.
The following instructions are for nuXmv setting. To use CBMC you can simply replace `workspace` with `workspace2` for each command.

Each benchmark model (`benchmark[index].scl` file) can be found in `benchmark/plcverif/cmd/workspace/benchmark[index]`,
along with its requirement specifications (`req[index].vc3`).

To run the first benchmark model with the first requirement file, use the following command in the top directory.
(PLCverif automatically locates and uses the corresponding .scl file.)

```
>./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark1/req1.vc3
PLCverif    by CERN BE-ICS-AP, (c) 2013-2019
   CLI version: 1.0.0.202012152221
--------------------------------------------
...
```



