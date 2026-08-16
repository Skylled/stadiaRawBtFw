// 60062ba4  usb_host_audio__60062ba4  size=178 bytes
// src: usb_host_audio.cc
// --- callers ---
//   60062f9c usb_host_audio__60062f9c
// --- callees ---
//   6010165c FUN_6010165c
//   600d1bdc FUN_600d1bdc
//   6013cf88 thunk_EXT_FUN_0000b4cc
//   600d5592 FUN_600d5592
//   60055ad0 FUN_60055ad0
//   600d55b8 FUN_600d55b8
//   6013cf90 thunk_EXT_FUN_0000b5ba


/* src: usb_host_audio.cc */

void usb_host_audio__60062ba4
               (int param_1,undefined4 *param_2,undefined1 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  
  puVar8 = param_3;
  iVar3 = FUN_600d5592(param_3);
  if (((param_3[1] != '\0') && (*(short *)(param_3 + 0xc) != iVar3)) &&
     (iVar4 = thunk_EXT_FUN_0000b4cc(param_1 + 0x974,0), puVar2 = DAT_60062c58, iVar4 != 0)) {
    *(undefined1 **)(param_1 + 0x108) = param_3;
    thunk_EXT_FUN_0000b5ba(puVar2 + 1,0,0x7e);
    iVar4 = *(int *)(param_1 + 0xec);
    *puVar2 = (short)iVar3;
    cVar1 = *(char *)(iVar4 + 0x79);
    if (cVar1 == '\0') {
      iVar3 = FUN_60055ad0(*param_2,*param_3,puVar2,1,DAT_60062c5c,param_1,puVar8,param_4);
      if (iVar3 == 0) {
        return;
      }
      uVar6 = 0x3bf;
      uVar5 = 0x1e;
      uVar7 = DAT_60062c60;
    }
    else {
      if (cVar1 == ' ') {
        iVar3 = FUN_600d1bdc(*param_2,*param_3,1,2,puVar2,0x80,DAT_60062c5c,param_1);
        if (iVar3 == 0) {
          return;
        }
        uVar6 = 0x3cc;
        uVar7 = DAT_60062c68;
      }
      else {
        uVar6 = 0x3d0;
        uVar7 = DAT_60062c6c;
      }
      uVar5 = 0x28;
    }
    FUN_6010165c(uVar5,DAT_60062c64,uVar6,uVar7);
    FUN_600d55b8(param_3);
    return;
  }
  return;
}


