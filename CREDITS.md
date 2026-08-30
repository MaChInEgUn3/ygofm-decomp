# Credits

## Unchiga

A second, independent matching decompilation of `SLUS_014.11`, shared on
2026-08-30, and also the author of the PSXRecomp-based native port of this
game. Working together was his suggestion and the credit is his request —
*"just give me credit"* — so it is stated here rather than buried in a
commit message.

What came from his tree, and what it is worth:

**Ported functions.** Every `src/func_*.c` whose header begins *"PORTED from
Unchiga's decompilation"* is his C. His code, his comments; the identifiers
were rewritten to this repo's address form and his per-unit compiler flags
carried across, and nothing else was touched. Each one was verified the only
way this repo accepts anything — `tools_src/build.py` rebuilds the retail
image byte-for-byte with it in place.

```
grep -l 'PORTED from Unchiga' src/*.c | wc -l
```

**The duel overlay.** `docs/DISC.txt` had spent weeks on three open questions:
which archive holds the overlay, what the container format is, and how to get
exact bytes. All three were already answered in his tree. His extractor, run
against a different disc image, produces the same 90,112-byte image
(sha1 `77b6430d…`) — which is what promotes it from *his reference* to *a
reference*. `tools_src/extract_overlay.py` is his algorithm, kept verbatim
under a docstring recording that check.

**Names.** `config/names_unchiga.txt` carries 1,035 semantic names from his
`symbol_addrs.txt` as annotation. Nothing here is renamed to match them; see
that file's header for why.

The method, tooling and prose of this tree are separate work, and
`docs/MERGE_UNCHIGA.md` keeps the two sides distinguishable on purpose — so
that neither of us is credited with the other's.

## Prior art consulted

- **Data Crystal / TCRF** — a community RAM map for the NTSC-U release, ten of
  whose addresses matched symbols already named here. Ingested under an
  `UNVERIFIED datacrystal/` label and never promoted to evidence by citation;
  the reasoning is in `docs/WORKFLOW.md`.
- The PS1/N64 matching-decomp community generally — `sotn-decomp`,
  `mgs_reversing`, `OpenDriver2` — for the practice this project copies:
  publish the reverse-engineered source, never the executable or the assets,
  and make every claim answer to a byte-exact rebuild.

## Handling

No game content is in this repository. `SLUS_014.11`, the disc image and
anything extracted from either are gitignored and must be supplied by whoever
builds it, from their own legally obtained copy.
