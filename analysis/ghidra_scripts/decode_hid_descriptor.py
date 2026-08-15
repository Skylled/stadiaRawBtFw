#!/usr/bin/env python3
"""Decode the Stadia HID report descriptor embedded in the bruce firmware.
The descriptor lives at flash 0x60103BA0 (file offset 0xC3BA0)."""
import sys

def main(path="reference_firmware/bruce_pvt_a_prod_signed.bin", start=0xC3BA0):
    d = open(path, "rb").read()
    rd = d[start:start + 300]
    usage_pages = {1: "Generic Desktop", 2: "Simulation", 9: "Button", 12: "Consumer", 15: "PID"}
    names = {(1, 0x30): "X", (1, 0x31): "Y", (1, 0x32): "Z", (1, 0x35): "Rz",
             (1, 0x39): "Hat", (1, 0x01): "Pointer", (1, 0x04): "Joystick", (1, 0x05): "Gamepad",
             (2, 0xC5): "Brake", (2, 0xC4): "Accelerator"}
    def sval(bs):
        v = 0
        for k, b in enumerate(bs):
            v |= b << (8 * k)
        return v
    i = 0; depth = 0; cur_up = 0; count = size = None
    while i < len(rd):
        b = rd[i]
        if b == 0xC0:
            depth -= 1; print("  " * depth + "End Collection"); i += 1
            if depth <= 0: break
            continue
        tag = b & 0xFC; ln = (b & 3) if (b & 3) < 3 else 4
        v = sval(rd[i + 1:i + 1 + ln]); t = None
        if tag == 0x04: t = f"Usage Page ({usage_pages.get(v, hex(v))})"; cur_up = v
        elif tag == 0x08: t = f"Usage ({names.get((cur_up, v), hex(v))})"
        elif tag in (0x84, 0x85): t = f"Report ID ({v})"
        elif tag == 0x74: t = f"Report Size ({v})"; size = v
        elif tag == 0x94: t = f"Report Count ({v})"; count = v
        elif tag == 0x14: t = f"Logical Min ({v})"
        elif tag == 0x24: t = f"Logical Max ({v})"
        elif tag == 0xA0: t = "Collection"; depth += 1
        elif tag == 0x80: t = f"INPUT (0x{v:02x})  [{count}x{size}b]"
        elif tag == 0x90: t = f"OUTPUT (0x{v:02x})  [{count}x{size}b]"
        elif tag == 0xB0: t = f"FEATURE (0x{v:02x})"
        else: t = f"item 0x{b:02x} v={v}"
        print("  " * depth + t); i += 1 + ln

if __name__ == "__main__":
    main(*sys.argv[1:])
