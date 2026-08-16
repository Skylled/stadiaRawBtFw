// 6006a21c  adapter__6006a21c  size=344 bytes
// src: adapter.cc
// --- callers ---
//   60081234 advertiser__60081234
//   60081c6c FUN_60081c6c
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   600d8a26 FUN_600d8a26
//   600d7d4c thunk_FUN_600d7cdc
//   600d3618 FUN_600d3618
//   6006d588 FUN_6006d588
//   6006d55c FUN_6006d55c
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600cc8f8 FUN_600cc8f8
//   600cc984 FUN_600cc984
//   601016f0 FUN_601016f0
//   60069130 FUN_60069130
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   6013cf40 thunk_EXT_FUN_00007d10
//   600ee278 FUN_600ee278
//   6006d534 FUN_6006d534
//   6013cef8 thunk_EXT_FUN_0000737c
//   600d8a18 FUN_600d8a18
//   6006bf74 FUN_6006bf74


/* src: adapter.cc */

undefined4 adapter__6006a21c(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 local_c8;
  undefined2 local_c4;
  undefined1 local_c0;
  undefined1 local_bf;
  undefined1 local_be;
  undefined1 local_bd;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined4 *local_b8;
  undefined4 local_b4;
  undefined1 auStack_b0 [144];
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x1ed4);
  if (*(char *)(param_1 + 0x11c) == '\x01') {
    iVar9 = param_1 + 0x110;
    FUN_6006d588(0);
    puVar5 = (undefined4 *)FUN_600d8a26(iVar9);
    local_c8 = *puVar5;
    local_b8 = &local_c8;
    local_c4 = *(undefined2 *)(puVar5 + 1);
    iVar6 = thunk_FUN_600d7cdc();
    puVar5 = (undefined4 *)PTR_s_<DII>_6006a384;
    if (iVar6 != 0) {
      FUN_60069130(local_b8,&local_b4,0x28);
      puVar5 = &local_b4;
    }
    FUN_6010165c(0x14,PTR_s_adapter_cc_6006a374,0x237,PTR_s_Bluetooth_MAC_Address___s_6006a378,
                 puVar5);
    puVar4 = DAT_6006a38c;
    pbVar3 = DAT_6006a388;
    puVar2 = PTR_s_adapter_cc_6006a374;
    local_c0 = local_c4._1_1_;
    local_bf = (undefined1)local_c4;
    local_be = local_c8._3_1_;
    local_bd = local_c8._2_1_;
    local_bc = local_c8._1_1_;
    local_bb = (undefined1)local_c8;
    FUN_6006d534(&local_c0);
    FUN_6006d55c(PTR_s__6011b41a_0xc_6006a37c);
    FUN_6006bf74();
    while (iVar6 = FUN_600ee278(), iVar6 == 0) {
      bVar1 = *pbVar3;
      DataMemoryBarrier(0x1b);
      if (((bVar1 & 1) == 0) && (iVar6 = FUN_600cc8f8(pbVar3), iVar6 != 0)) {
        *puVar4 = bVar1 & 1;
        FUN_600cc984(pbVar3);
      }
      uVar7 = FUN_600d3618();
      if (*puVar4 + 500 <= uVar7) {
        *puVar4 = uVar7;
        local_b8 = (undefined4 *)puVar2;
        local_b4 = 0x242;
        FUN_600d3b3a(auStack_b0);
        FUN_600d37ac(auStack_b0,PTR_s_Waiting_for_BLE_to_come_up____6006a380);
        FUN_601016f0(0x14,local_b8,local_b4,auStack_b0);
      }
      thunk_EXT_FUN_0000737c(10);
    }
    iVar6 = FUN_600d8a26(iVar9);
    uVar8 = *(undefined4 *)(iVar6 + 8);
    if (*(char *)(param_1 + 0x11c) == '\x02') {
      puVar5 = (undefined4 *)FUN_600d8a18(iVar9);
      *puVar5 = uVar8;
    }
    else {
      *(undefined4 *)(param_1 + 0x110) = uVar8;
      *(undefined1 *)(param_1 + 0x11c) = 2;
      FUN_600d8a18(iVar9);
    }
    uVar8 = 0;
  }
  else {
    uVar8 = 9;
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x1ed4);
  return uVar8;
}


