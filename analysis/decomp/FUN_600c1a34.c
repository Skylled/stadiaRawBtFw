// 600c1a34  FUN_600c1a34  size=220 bytes
// --- callers ---
//   600faec4 FUN_600faec4
//   600c0434 FUN_600c0434
//   600fbae0 FUN_600fbae0
//   600fc302 FUN_600fc302
//   600fb848 FUN_600fb848
//   600fa8d6 FUN_600fa8d6
//   600c1204 FUN_600c1204
//   600fb6de FUN_600fb6de
//   600c0640 FUN_600c0640
//   600c073c FUN_600c073c
//   600bffe8 FUN_600bffe8
//   600fbd4c FUN_600fbd4c
//   600fb24a FUN_600fb24a
//   600fb8c4 FUN_600fb8c4
//   600fb9d2 FUN_600fb9d2
//   600fc380 FUN_600fc380
//   600fb626 FUN_600fb626
//   600c1b74 FUN_600c1b74
//   600fb6aa FUN_600fb6aa
//   600fba9c FUN_600fba9c
//   600c229c FUN_600c229c
//   600fb160 FUN_600fb160
//   600fc110 FUN_600fc110
//   600fc9aa FUN_600fc9aa
//   600fc29c FUN_600fc29c
//   600c03d8 FUN_600c03d8
//   600c05e4 FUN_600c05e4
//   600c1864 FUN_600c1864
//   600fb110 FUN_600fb110
//   600c0d3c FUN_600c0d3c
//   600c1030 FUN_600c1030
//   600c0294 FUN_600c0294
//   600c1788 FUN_600c1788
//   600fc260 FUN_600fc260
//   600c1c04 FUN_600c1c04
//   600fc3da FUN_600fc3da
//   600fba06 FUN_600fba06
//   600fc7ca FUN_600fc7ca
//   600c0698 FUN_600c0698
//   600fb1e6 FUN_600fb1e6
//   600fb2ae FUN_600fb2ae
//   600c15a8 FUN_600c15a8
//   600fbdd0 FUN_600fbdd0
//   600c0114 FUN_600c0114
//   600fbab8 FUN_600fbab8
//   600fb5dc FUN_600fb5dc
//   600fb53e FUN_600fb53e
//   600fb0ac FUN_600fb0ac
//   600fadb6 FUN_600fadb6
//   600fc17a FUN_600fc17a
//   600fae72 FUN_600fae72
//   600fc2c6 FUN_600fc2c6
//   600c0578 FUN_600c0578
//   600c1988 FUN_600c1988
// --- callees ---
//   600c19f4 FUN_600c19f4


void FUN_600c1a34(int param_1,byte param_2,undefined4 param_3)

{
  byte bVar1;
  byte local_e;
  byte local_d;
  int local_c;
  
  bVar1 = *(byte *)(param_1 + 0x23);
  if (((bVar1 < 0x11) && (param_2 < 0x29)) &&
     (local_d = *(byte *)(*(int *)(DAT_600c1b10 + (uint)*(byte *)(param_1 + 0x26) * 4) +
                          (uint)param_2 * 0x11 + -0x11 + (uint)bVar1), local_d != 0)) {
    if ((char)local_d < '\0') {
      local_d = local_d & 0x7f;
      local_c = DAT_600c1b14;
    }
    else {
      local_c = *(int *)(DAT_600c1b18 + ((uint)bVar1 * 2 + (uint)*(byte *)(param_1 + 0x26)) * 4);
    }
    FUN_600c19f4(*(undefined1 *)((uint)local_d * 3 + local_c + -1));
    for (local_e = 0;
        (local_e < 2 &&
        (bVar1 = *(byte *)(local_c + (uint)local_d * 3 + -3 + (uint)local_e), bVar1 != 0x3d));
        local_e = local_e + 1) {
      (**(code **)(DAT_600c1b1c + (uint)bVar1 * 4))(param_1,param_3);
    }
  }
  return;
}


