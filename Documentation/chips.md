List of chips for extending WP support in flashrom as of 26 July 2022.

|   Manufacturer    |     Model(s)     | Upstream | [flashrom#185] |  test results |Notes
| ----------------- | ---------------- | -------- | -------------- |---------------|-----
| Atmel             | `AT25SL128A`     | +        |                |               |
| Eon               | `EN25QH128`      | +        |                |               |
| ^                 | `EN25QH32`       |          | +              |               |
| ^                 | `EN25QH64`       |          | +              |               |
| GigaDevice        | `GD25LQ64`       | +        |                |               |
| ^                 | `GD25LQ64B`      | +        |                |               |
| ^                 | `GD25LQ128C`     | +        |                |               |
| ^                 | `GD25LQ128D`     | +        |                |               |
| ^                 | `GD25LQ128E`     | +        |                |               |
| ^                 | `GD25Q32`        | +        |                |               |
| ^                 | `GD25Q32B`       | +        |                |               |
| ^                 | `GD25Q64`        | +        |                |               |
| ^                 | `GD25Q64B`       | +        |                |               |
| ^                 | `GD25Q127C`      | +        |                |               |
| ^                 | `GD25Q128C`      | +        |                |               |
| ^                 | `GD25Q256D`      | +        |                |               |
| Winbond           | `W25Q32.V`       |          | +              |               |
| ^                 | `W25Q32.W`       |          | +              |               |
| ^                 | `W25Q64BV`       | +        | +              |               |
| ^                 | `W25Q64CV`       | +        | +              |               |
| ^                 | `W25Q64FV`       | +        | +              |               |in KGPE-D16
| ^                 | `W25Q64JV-.Q`    | +        | +              |               |
| ^                 | `W25Q64.W`       | +        | +              |               |in Protectli FW4C
| ^                 | `W25Q128.V`      | +        |                |               |in KGPE-D16
| ^                 | `W25Q128.V..M`   | +        |                |               |
| ^                 | `W25Q128.W`      | +        |                |               |
| ^                 | `W25Q128.JW.DTR` | +        |                |               |
| ^                 | `W25Q256.V`      | +        |                |               |
| ^                 | `W25Q256JV_M`    | +        |                |               |
| Macronix          | `MX25L3206E`     |          | +              | [MX25L3206E]  |in Dell OptiPlex
| ^                 | `MX25L3208E`     |          | +              |               |same flash description as MX25L3206E
| ^                 | `MX25L6405`      |          | +              |               |
| ^                 | `MX25L6405D`     |          | +              |               |
| ^                 | `MX25L6406E`     |          | +              |               |in Dell OptiPlex
| ^                 | `MX25L6408E`     |          | +              |               |same flash description as MX25L6406E
| ^                 | `MX25L6436E`     |          | +              | [MX25L6436E]  |
| ^                 | `MX25L6445E`     |          | +              |               |
| ^                 | `MX25L6465E`     |          | +              |               |
| ^                 | `MX25L6473E`     |          | +              |               |
| ^                 | `MX25L6473F`     |          | +              |               |
| ^                 | `MX25L6495F`     |          | +              |               |**no datasheet!**
| Micron/Numonyx/ST | `N25Q032..1E`    |          | +              |               |
| ^                 | `N25Q032..3E`    |          | +              |               |
| ^                 | `N25Q064..1E`    |          | +              |               |
| ^                 | `N25Q064..3E`    |          | +              |               |
| ^                 | `MT25QL512ABB8ESF-0SIT` |   |                |               |in Talos II
| XTX               | `XT25F16`        |          | optional       |optional       |

[flashrom#185]: https://github.com/flashrom/flashrom/issues/185
[MX25L3206E]: MX25L3206E.md
[MX25L6436E]: MX25L6436E.md
