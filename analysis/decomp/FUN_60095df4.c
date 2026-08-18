// 60095df4  FUN_60095df4  size=74 bytes
// --- callers ---
//   600a9f10 FUN_600a9f10
// --- callees ---
//   600efd62 FUN_600efd62
//   600a1368 FUN_600a1368
//   6006e594 FUN_6006e594
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6009625c FUN_6009625c


void FUN_60095df4(void)

{
  undefined1 uVar1;
  
  thunk_EXT_FUN_0000b5ba(DAT_60095e40,0,0x170);
  FUN_600efd62(DAT_60095e48,1000,*(undefined1 *)(*DAT_60095e44 + 3));
  uVar1 = FUN_6006e594();
  *(undefined1 *)(DAT_60095e40 + 0x115) = uVar1;
  *DAT_60095e50 = *DAT_60095e4c;
  FUN_6009625c(0,DAT_60095e54);
  FUN_600a1368(DAT_60095e58);
  return;
}


