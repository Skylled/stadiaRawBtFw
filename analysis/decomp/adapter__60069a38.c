// 60069a38  adapter__60069a38  size=204 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d8892 FUN_600d8892
//   600d8994 FUN_600d8994
//   600d3618 FUN_600d3618
//   6010165c FUN_6010165c
//   600cc8f8 FUN_600cc8f8
//   600d37ac FUN_600d37ac
//   600d3b3a FUN_600d3b3a
//   600cc984 FUN_600cc984
//   6006ae20 gatt_server__6006ae20
//   601016f0 FUN_601016f0
//   600d8946 FUN_600d8946


/* src: adapter.cc */

void adapter__60069a38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined2 param_5,undefined1 param_6)

{
  byte bVar1;
  undefined4 uVar2;
  uint *puVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_b0 [144];
  
  iVar5 = FUN_600d8994(param_1 + 0x110);
  if (iVar5 == 0) {
    FUN_6010165c(0x28,DAT_60069b08,0x36c,DAT_60069b0c,DAT_60069b04);
  }
  else {
    iVar5 = FUN_600d8946(param_1 + 0x1ab4,param_2);
    pbVar4 = DAT_60069b1c;
    puVar3 = DAT_60069b10;
    if (iVar5 == 0) {
      FUN_6010165c(0x28,DAT_60069b08,0x371,DAT_60069b18);
    }
    else {
      bVar1 = *DAT_60069b1c;
      DataMemoryBarrier(0x1b);
      if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_60069b1c), iVar5 != 0)) {
        *puVar3 = bVar1 & 1;
        FUN_600cc984(pbVar4);
      }
      uVar6 = FUN_600d3618();
      uVar2 = DAT_60069b08;
      if (*puVar3 + 500 <= uVar6) {
        *puVar3 = uVar6;
        FUN_600d3b3a(auStack_b0);
        FUN_600d37ac(auStack_b0,DAT_60069b14);
        FUN_600d8892(auStack_b0,param_4);
        FUN_601016f0(10,uVar2,0x374,auStack_b0);
      }
      gatt_server__6006ae20(param_1 + 0x13c,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return;
}


