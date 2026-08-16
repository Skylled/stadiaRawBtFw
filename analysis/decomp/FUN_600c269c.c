// 600c269c  FUN_600c269c  size=332 bytes
// --- callers ---
// --- callees ---
//   60099768 FUN_60099768
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60099c9c FUN_60099c9c
//   6009ab40 FUN_6009ab40
//   600a1238 FUN_600a1238
//   6009a114 FUN_6009a114
//   60095b9c FUN_60095b9c
//   60093478 FUN_60093478
//   600d9190 thunk_FUN_6006ce40
//   60095b7c FUN_60095b7c
//   600a12e0 FUN_600a12e0
//   600f17da FUN_600f17da
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60095f10 FUN_60095f10
//   600a3f40 FUN_600a3f40


void FUN_600c269c(char param_1)

{
  undefined1 auStack_54 [48];
  undefined1 auStack_24 [19];
  byte local_11;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  local_11 = 0;
  if (param_1 == '\0') {
    if (*(int *)(DAT_600c27e8 + 0xe8) != 0) {
      (**(code **)(DAT_600c27e8 + 0xe8))(1,0);
    }
    thunk_EXT_FUN_0000b5ba(DAT_600c27e8,0,0x294);
    FUN_60095f10(0);
    *DAT_600c27e8 = 0;
  }
  else if (param_1 == '\x01') {
    FUN_60095f10(0);
    local_c = *(undefined4 *)(DAT_600c27e8 + 0xe8);
    thunk_EXT_FUN_0000b5ba(DAT_600c27e8,0,0x294);
    *(undefined4 *)(DAT_600c27e8 + 0xe8) = local_c;
    *DAT_600c27e8 = 1;
    thunk_EXT_FUN_0000b5ba(DAT_600c27ec,0,0x16c);
    thunk_EXT_FUN_0000b5ba(DAT_600c27f0,0,0x65);
    thunk_EXT_FUN_0000b5ba(DAT_600c27f4,0,0x14);
    thunk_EXT_FUN_0000b572(auStack_10,PTR_DAT_600c27f8,3);
    FUN_600a12e0(auStack_10);
    thunk_FUN_6006ce40(&local_11,auStack_24,auStack_54);
    if ((local_11 & 2) != 0) {
      FUN_6009ab40(2,auStack_24);
    }
    if ((local_11 & 1) != 0) {
      FUN_6009ab40(1,auStack_54);
    }
    *(undefined2 *)(DAT_600c27ec + 0x14a) = 0xffff;
    FUN_600a3f40(PTR_PTR_600c27fc);
    FUN_60099c9c(*(undefined2 *)(PTR_DAT_600c27f8 + 8));
    FUN_600f17da(*(undefined2 *)(PTR_DAT_600c27f8 + 6));
    *(undefined2 *)(DAT_600c27e8 + 0x240) = *(undefined2 *)(PTR_DAT_600c27f8 + 4);
    FUN_60099768(*(undefined2 *)(DAT_600c27e8 + 0x240));
    FUN_6009a114(PTR_LAB_600c4c58_1_600c2800);
    FUN_600a1238(PTR_LAB_600c4af8_1_600c2804);
    FUN_60095b7c(PTR_LAB_600c52cc_1_600c2808);
    FUN_60093478();
    FUN_60095b9c(PTR_FUN_600c2d5c_1_600c280c);
  }
  return;
}


