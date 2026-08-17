// 60068a00  battery_gauge_bq2742X__60068a00  size=212 bytes
// src: battery_gauge_bq2742X.cc
// --- callers ---
//   60068cb4 battery_gauge_bq2742X__60068cb4
// --- callees ---
//   600cedd8 FUN_600cedd8
//   60068970 FUN_60068970
//   600d49ce FUN_600d49ce
//   6013cef8 thunk_EXT_FUN_0000737c
//   600d49e2 FUN_600d49e2
//   6010165c FUN_6010165c


/* src: battery_gauge_bq2742X.cc */

undefined4 battery_gauge_bq2742X__60068a00(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  int iStack_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  int local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_6010165c(0x28,DAT_60068ad8,0x123,DAT_60068ad4);
    uVar1 = 0xc;
  }
  else {
    local_44 = *puVar3;
    uStack_40 = puVar3[1];
    uStack_3c = puVar3[2];
    uStack_38 = puVar3[3];
    local_34 = puVar3[4];
    iStack_30 = puVar3[5];
    local_2c = puVar3[6];
    uVar1 = 0;
    uVar2 = iStack_30 - 1;
    local_28 = 2;
    local_20 = 1;
    local_27 = 0;
    local_26 = 0;
    local_24 = 0;
    if (uVar2 < 5) {
      local_24 = DAT_60068adc;
    }
    local_1f = 0;
    if (uVar2 < 5) {
      local_24 = *(int *)(local_24 + uVar2 * 4);
    }
    local_1e = 0;
    local_1d = 0;
    local_1c = 6;
    local_1b = 0;
    local_1a = 1;
    local_19 = 0;
    FUN_600d49ce(&local_44);
    thunk_EXT_FUN_0000737c(1);
    FUN_600cedd8(local_24,local_2c,0);
    thunk_EXT_FUN_0000737c(1);
    FUN_600cedd8(local_24,local_2c,1);
    FUN_600d49e2(&local_44);
    FUN_60068970(param_1);
    thunk_EXT_FUN_0000737c(500);
  }
  return uVar1;
}


