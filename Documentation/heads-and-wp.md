## Updating Heads

Whether Heads is to be updated in full or only in part makes no difference for
the choice of the flash image, it's always the same full flash image.

### Updating Heads after the bootblock has been locked

When the patched `flashrom` detects an attempt to flash a write protected chip,
it prints a warning informing the user about potential danger of proceeding and
suggests to use `--skip-wp-area` parameter to perform the operation.

When `--skip-wp-area` is passed in, the danger warning is still printed, but
the code goes further and creates a custom layout which covers the whole chip
with the exception of its write-protected part. Because there is no way to
combine a loaded layout with a custom one in a meaningful way, the code fails
if chip layout is in use (there are multiple parameters to load it, they are all
treated the same way).

#### Risks of partial updates

Partial updates can produce an unbootable image if old bootblock doesn't work
with a more recent version of `coreboot`. This can be manifested in various
ways ranging from old bootblock not being able to find new romstage to system
booting successfully, but data in `coreboot` tables being mangled or incomplete.

The incompatibilities might happen when switching version of firmware or when
using the same version with a slightly different configuration.

Another thing that can potentially cause trouble is CBFS layout. When bootblock
is part of CBFS, it doesn't necessarily have a fixed address, moreover it can
change location as well if it depends on file size (when bootblock's last byte
must be the last byte of the image). If newer bootblock is smaller such that an
old WP range now covers bootblock and some other file, this file won't be fully
updated due to write-protection, potentially resulting in a corrupt image.
Luckily, when bootblock is the last file it's normally preceded by a
significant amount of empty space, which won't let this situation to occur.

On top of that, last 4 bytes of the image contain offset to the master header of
CBFS. Depending on the coreboot version this offset might be crucial for the
loading of romstage, in which case moving CBFS within the image without updating
of the offset (when it's blocked by WP) can also break booting process.

#### Recovering from a broken state

Since broken flash won't let the system to boot, the way to fix it is to flash
the chip externally by connecting it to a different device. A possible
alternative could be to have a backup flash created beforehand and swapping it
for the broken one.

### Flashing whole Heads image

The function of the hardware protection mechanism (`W#` or `W/` pin of flash
chips) is to lock state of software protection preventing it from being
disabled. After the chip is physically unlocked by changing the state of the
pin, the state of the write protection doesn't change. However, in this state
the protection can be easily turned off programmatically, which is what
`flashrom` tries to do before performing an operation on a chip.

In other words, changing state of the WP pin might be enough to be able to
flash the chip in full. If `flashrom` errors or you don't want to rely on the
automatic behaviour, you can try to explicitly disable the protection by running
`flashrom` like this:

```
flashrom --wp-disable
```

If you need to pass extra parameters to flash your chip (e.g., programmer or
chip name), add them to the above command (order of such parameters shouldn't
matter).

Mind that in `flashrom` the code for disabling protection automatically is
different from the code for processing `--wp-disable`. This means that they can
sometimes produce different results, which is why you should be aware about both
code paths that affect WP.
