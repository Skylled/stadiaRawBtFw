// 600bb2ac  FUN_600bb2ac  size=96 bytes
// --- callers ---
//   600aa534 FUN_600aa534
// --- callees ---
//   600b8d7c FUN_600b8d7c
//   600bb15c FUN_600bb15c
//   600b5e00 FUN_600b5e00
//   600f8aea FUN_600f8aea


void FUN_600bb2ac(int param_1)

{
  switch(*(undefined2 *)(param_1 + 0x14)) {
  case 2:
    FUN_600b8d7c(*(undefined4 *)(param_1 + 0x10));
    break;
  case 3:
    FUN_600b5e00(*(undefined4 *)(param_1 + 0x10),0x20,0);
    break;
  case 4:
    FUN_600bb15c(1);
    break;
  case 0x2a:
    FUN_600b5e00(*(undefined4 *)(param_1 + 0x10),0x22,0);
    break;
  case 0x2b:
    FUN_600f8aea(*(undefined4 *)(param_1 + 0x10));
  }
  return;
}


