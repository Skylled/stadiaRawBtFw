// 600a0bc4  FUN_600a0bc4  size=218 bytes
// --- callers ---
//   60098cc4 FUN_60098cc4
//   600a0600 FUN_600a0600
//   600a0cac FUN_600a0cac
//   600a0730 FUN_600a0730
//   600a068c FUN_600a068c
// --- callees ---
//   600a8410 FUN_600a8410
//   600aa3cc FUN_600aa3cc
//   600a08c4 FUN_600a08c4
//   600a17c0 FUN_600a17c0
//   600a12e0 FUN_600a12e0


void FUN_600a0bc4(void)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  code *pcVar4;
  undefined1 local_b;
  undefined1 local_a;
  
  iVar2 = DAT_600a0ca0;
  pcVar4 = *(code **)(DAT_600a0ca0 + 0x2c);
  bVar1 = false;
  FUN_600aa3cc(DAT_600a0ca4);
  for (local_a = 2; bVar3 = local_a, -1 < (char)local_a; local_a = local_a - 1) {
    for (local_b = 0; local_b < 8; local_b = local_b + 1) {
      if (*(char *)((uint)local_b + (char)local_a * 8 + iVar2 + 0x123) != '\0') {
        bVar1 = true;
        break;
      }
    }
    if ((bVar1) || (local_a == 0)) break;
  }
  *(undefined1 *)(iVar2 + 0x191) = 2;
  FUN_600a12e0(DAT_600a0ca8);
  local_a = '\0';
  while( true ) {
    if ((int)(uint)bVar3 < (int)(char)local_a) break;
    FUN_600a08c4(local_a,((char)local_a + 0x24) * 8 + iVar2 + 3);
    local_a = local_a + '\x01';
  }
  FUN_600a8410();
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  FUN_600a17c0(0);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(0);
  }
  return;
}


