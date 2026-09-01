# Unchiga_Symbols — named-symbol research for SLUS_014.11

Symbol research from Unchiga's matching decompilation of Yu-Gi-Oh! Forbidden
Memories (SLUS-01411, USA). Every applied name in these documents survived a
byte-identical rebuild of the original executable (MD5
`dab1b3c9a6b8a56558b5ca8f807339c3`), and names marked as live-traced were
verified against the running game (function-entry tracing, RAM diffing, and
injected input on a recompiled build).

What's here:

| file | contents |
|---|---|
| `symbols_guide.md` | The headline document: confirmed symbols organized by game area (menus, options, password, library, build deck, free duel, duel, save file, sound driver, debug leftovers), in plain English. |
| `known_functions.md` | All 1,073 named functions, sectioned game-meaningful / SDK / mechanical, each tagged with its evidence source. |
| `known_variables.md` | All 63 named variables/data symbols, same treatment. |
| `descriptions.md` | The naming gate: a short verified description for every properly named function (128 rows so far; variables pending). |
| `findings.md` | The raw live-trace evidence ledger (F1-F69): what was proven, how, and what status each claim holds. |
| `suspects.md` | Suspected/WIP identifications that are NOT yet 100% — each with the evidence gathered and what would graduate it. |
| `NAMING.md` | The conventions: where each kind of name comes from (PsyQ signatures, the 2018 community IDA db, the DotR SLUS-20515 symbol vocabulary, live tracing) and how much to trust each tier. |

Ground rules these documents follow: disputed names are quarantined rather
than mixed in; hedged names (`maybe_*`, `u_*`) never pass the gate; and a
name only counts as done once its description matches the matched code or a
live observation. Corrections and counter-evidence welcome.

Source repository: Unchiga/ygofm-decomp (private); contact Unchiga for
access or questions.
