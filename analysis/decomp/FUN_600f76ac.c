// 600f76ac  FUN_600f76ac  size=288 bytes
// --- callers ---
//   600f768a FUN_600f768a
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600bc1a8 FUN_600bc1a8
//   6006e0a4 FUN_6006e0a4
//   600b5e00 FUN_600b5e00
//   600bb44c FUN_600bb44c
//   600bc480 FUN_600bc480
//   600bbd3c FUN_600bbd3c
//   600bb6dc FUN_600bb6dc


undefined2 FUN_600f76ac(undefined2 param_1,undefined4 param_2,undefined4 *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  int local_c;
  
  iVar2 = FUN_600a01a0();
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    iVar2 = FUN_600bc1a8(param_1);
    if (iVar2 == 0) {
      uVar5 = 0;
    }
    else {
      local_c = FUN_600bb6dc(param_2,1);
      if ((local_c == 0) &&
         ((local_c = FUN_600bb44c(param_2,0,1), local_c == 0 ||
          (iVar3 = FUN_600bc480(local_c,1), iVar3 == 0)))) {
        return 0;
      }
      puVar4 = (undefined2 *)FUN_600bbd3c(local_c,0);
      if (puVar4 == (undefined2 *)0x0) {
        uVar5 = 0;
      }
      else {
        *(int *)(puVar4 + 0xaa) = iVar2;
        if (param_3 != (undefined4 *)0x0) {
          *(undefined4 *)((int)puVar4 + 0xa7) = *param_3;
          *(undefined2 *)((int)puVar4 + 0xab) = *(undefined2 *)(param_3 + 1);
          if (*(char *)((int)puVar4 + 0xab) == -1) {
            *(undefined1 *)((int)puVar4 + 0xab) = 2;
          }
          if (*(char *)(puVar4 + 0x56) == -1) {
            *(undefined1 *)(puVar4 + 0x56) = 2;
          }
          if (*(char *)((int)puVar4 + 0xa9) == -1) {
            *(undefined1 *)((int)puVar4 + 0xa9) = 2;
          }
          if (*(char *)(puVar4 + 0x55) == -1) {
            *(undefined1 *)(puVar4 + 0x55) = 2;
          }
          sVar1 = FUN_6006e0a4(*(undefined1 *)((int)param_3 + 2));
          puVar4[0x8d] = sVar1 + -0x11;
        }
        if (*(char *)(local_c + 1) == '\x04') {
          FUN_600b5e00(puVar4,0x15,0);
        }
        else if (*(char *)(local_c + 1) == '\x05') {
          *(undefined2 **)(local_c + 100) = puVar4;
        }
        uVar5 = *puVar4;
      }
    }
  }
  return uVar5;
}


