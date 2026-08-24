// 600edc74  FUN_600edc74  size=12 bytes
// --- callers ---
// --- callees ---
//   60091c10 obj__60091c10


undefined4 FUN_600edc74(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = obj__60091c10();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}


