#!/usr/bin/env node

import * as scrambler from "./scrambler";
import * as yargs from "yargs";

const argv = yargs.options({
  scramble: { type: "string", alias: "s" },
}).argv;

if (argv.scramble) {
  console.log(scrambler.scramble());
}
