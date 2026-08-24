// 600edc68  FUN_600edc68  size=12 bytes
// --- callers ---
//   60086b98 FUN_60086b98
// --- callees ---
//   60091c10 obj__60091c10


undefined4 FUN_600edc68(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)obj__60091c10();
  uVar2 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *puVar1;
  }
  return uVar2;
}


