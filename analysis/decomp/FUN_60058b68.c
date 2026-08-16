// 60058b68  FUN_60058b68  size=100 bytes
// --- callers ---
// --- callees ---
//   60101b0c FUN_60101b0c
//   601016f0 FUN_601016f0
//   60101ba2 FUN_60101ba2
//   60101b76 FUN_60101b76


void FUN_60058b68(char *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool in_ZR;
  bool in_CY;
  undefined1 *puStack_98;
  int iStack_94;
  int iStack_90;
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  undefined1 auStack_8a [130];
  
  uVar1 = DAT_60058bd4;
  if ((!in_CY || in_ZR) && (param_1 != (char *)0x0)) {
    if (*param_1 == '\x05') {
      hid_input_target__60058aa8(param_1 + 1);
    }
    else {
      puStack_98 = auStack_8a;
      iStack_94 = 0x80;
      iStack_90 = 0;
      uStack_8c = 0;
      uStack_8b = 0;
      auStack_8a[0] = 0;
      FUN_60101b76(&puStack_98,DAT_60058bd8);
      uVar2 = FUN_60101b0c(*param_1,0,puStack_98 + iStack_90,iStack_94 - iStack_90);
      FUN_60101ba2(&puStack_98,uVar2);
      FUN_601016f0(0x1e,uVar1,0xaf,&puStack_98);
    }
  }
  return;
}


