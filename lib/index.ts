#!/usr/bin/env node

import { scramble } from "./scrambler";
import * as yargs from "yargs";
import * as chalk from "chalk";

const argv = yargs.options({
  scramble: {
    type: "string",
    alias: "s",
    description: "Generate random scramble algorithm for given cube",
  },
  timer: {
    type: "boolean",
    alias: "t",
    description: "Launch timer mode",
  },
}).argv;

if (argv.scramble || argv.scramble === "") {
  switch (argv.scramble) {
    default:
      console.log(scramble(3));
      break;
  }
} else {
  yargs.showHelp();
}
