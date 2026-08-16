// 60062c70  usb_host_audio__60062c70  size=160 bytes
// src: usb_host_audio.cc
// --- callers ---
//   60062f9c usb_host_audio__60062f9c
// --- callees ---
//   6010165c FUN_6010165c
//   600d1bdc FUN_600d1bdc
//   6013cf88 thunk_EXT_FUN_0000b4cc
//   60055ad0 FUN_60055ad0
//   6013cf90 thunk_EXT_FUN_0000b5ba


/* src: usb_host_audio.cc */

void usb_host_audio__60062c70
               (int param_1,undefined4 *param_2,undefined1 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_3[1] != '\0') {
    if ((param_3[2] != param_3[3]) &&
       (iVar4 = thunk_EXT_FUN_0000b4cc
                          (param_1 + 0x974,0,param_3[2],param_3[3],param_1,param_2,param_3,param_4),
       puVar3 = DAT_60062d10, iVar4 != 0)) {
      thunk_EXT_FUN_0000b5ba(DAT_60062d10,0,0x80);
      uVar1 = param_3[2];
      *(undefined1 **)(param_1 + 0x10c) = param_3;
      *puVar3 = uVar1;
      cVar2 = *(char *)(*(int *)(param_1 + 0xec) + 0x79);
      if (cVar2 == '\0') {
        iVar4 = FUN_60055ad0(*param_2,*param_3,puVar3,0,DAT_60062d14,param_1);
        if (iVar4 == 0) {
          return;
        }
        uVar6 = 0x398;
        uVar5 = 0x1e;
        uVar7 = DAT_60062d18;
      }
      else {
        if (cVar2 == ' ') {
          iVar4 = FUN_600d1bdc(*param_2,*param_3,1,1,puVar3,0x80,DAT_60062d14,param_1);
          if (iVar4 == 0) {
            return;
          }
          uVar6 = 0x3a5;
          uVar7 = DAT_60062d20;
        }
        else {
          uVar6 = 0x3a9;
          uVar7 = DAT_60062d24;
        }
        uVar5 = 0x28;
      }
      FUN_6010165c(uVar5,DAT_60062d1c,uVar6,uVar7);
      param_3[2] = param_3[3];
    }
  }
  return;
}


