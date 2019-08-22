#pragma once

struct serial_icounter_struct {
    int cts, dsr, rng, dcd;
    int rx, tx;
    int frame, overrun, parity, brk;
    int buf_overrun;
    int reserved[9];
};