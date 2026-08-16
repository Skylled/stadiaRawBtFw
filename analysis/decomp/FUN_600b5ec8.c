// 600b5ec8  FUN_600b5ec8  size=620 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600bc00c FUN_600bc00c
//   600aa3cc FUN_600aa3cc
//   600f8de8 FUN_600f8de8
//   6006ddd8 FUN_6006ddd8
//   600f83f2 FUN_600f83f2
//   600f8d34 FUN_600f8d34
//   600aa340 FUN_600aa340
//   600f0552 FUN_600f0552
//   600a4c5c FUN_600a4c5c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a3424 FUN_600a3424


void FUN_600b5ec8(undefined2 *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_30 [8];
  undefined1 local_28;
  undefined1 auStack_24 [8];
  undefined1 local_1c;
  code *local_18;
  code *local_14;
  undefined2 local_e;
  int local_c;
  
  local_e = *param_1;
  if (*(int *)(param_1 + 0xaa) != 0) {
    local_14 = *(code **)(*(int *)(param_1 + 0xaa) + 0x1c);
    local_18 = *(code **)(*(int *)(param_1 + 0xaa) + 0xc);
    local_c = param_3;
    switch(param_2) {
    case 0:
      *(undefined1 *)(param_1 + 2) = 1;
      FUN_600a4c5c(*(int *)(param_1 + 0x96) + 4,*(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
                   *(undefined2 *)(*(int *)(param_1 + 0x96) + 2),1,DAT_600b61bc,param_1);
      break;
    case 1:
      if ((*(char *)(param_3 + 6) != '\v') ||
         (iVar1 = FUN_600f0552(*(int *)(param_1 + 0x96) + 4), iVar1 == 0)) {
        FUN_600bc00c(param_1);
        (*local_18)(local_e,*(undefined1 *)(local_c + 6));
      }
      break;
    case 3:
      FUN_600bc00c(param_1);
      (*local_14)(local_e,0);
      break;
    case 7:
      *(undefined1 *)(param_1 + 2) = 3;
      if (*(char *)(*(int *)(param_1 + 0x96) + 0xa3) == '\0') {
        iVar1 = FUN_600f83f2(param_1);
        if (iVar1 == 0) {
          FUN_600bc00c(param_1);
          (*local_18)(local_e,0xff);
        }
        else {
          FUN_600f8d34(param_1);
          FUN_600aa340(param_1 + 0x9e,3,0x3c);
        }
      }
      break;
    case 8:
      FUN_600bc00c(param_1);
      (*local_18)(local_e,3);
      break;
    case 10:
      FUN_600aa3cc(*(int *)(param_1 + 0x96) + 0x44);
      thunk_EXT_FUN_0000b5ba(auStack_30,0,10);
      local_28 = 0;
      FUN_600a3424(0x80,*(int *)(param_1 + 0x96) + 4,auStack_30);
      if (*(char *)(*(int *)(param_1 + 0x96) + 0xa3) != '\0') {
        FUN_600aa340(*(int *)(param_1 + 0x96) + 0x68,0x2b,3);
      }
      *(undefined1 *)(param_1 + 2) = 2;
      iVar1 = FUN_600a4c5c(*(int *)(param_1 + 0x96) + 4,
                           *(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
                           *(undefined2 *)(*(int *)(param_1 + 0x96) + 2),0,DAT_600b61bc,param_1);
      if (iVar1 == 1) {
        FUN_600f8de8(param_1,1,0);
      }
      break;
    case 0x14:
    case 0x1e:
      FUN_6006ddd8(param_3,DAT_600b61c0,0x10c);
      break;
    case 0x15:
      thunk_EXT_FUN_0000b5ba(auStack_24,0,10);
      local_1c = 0;
      FUN_600a3424(0x80,*(int *)(param_1 + 0x96) + 4,auStack_24);
      if (*(char *)(*(int *)(param_1 + 0x96) + 0xa3) != '\0') {
        FUN_600aa340(*(int *)(param_1 + 0x96) + 0x68,0x2b,3);
      }
      iVar1 = FUN_600a4c5c(*(int *)(param_1 + 0x96) + 4,
                           *(undefined2 *)(*(int *)(param_1 + 0xaa) + 2),
                           *(undefined2 *)(*(int *)(param_1 + 0x96) + 2),1,DAT_600b61bc,param_1);
      if (iVar1 == 1) {
        *(undefined1 *)(param_1 + 2) = 1;
      }
      break;
    case 0x1b:
      FUN_600bc00c(param_1);
      break;
    case 0x20:
      FUN_600bc00c(param_1);
      (*local_18)(local_e,0xeeee);
    }
  }
  return;
}


