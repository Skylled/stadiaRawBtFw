// 60079d28  audio_tasks__60079d28  size=158 bytes
// src: audio_tasks.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6007e784 FUN_6007e784
//   600da478 FUN_600da478
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6007eb8c FUN_6007eb8c
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010165c FUN_6010165c
//   60079bf4 FUN_60079bf4
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d3c8 thunk_EXT_FUN_00001680
//   60079c6c FUN_60079c6c


/* src: audio_tasks.cc */

bool audio_tasks__60079d28(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  int local_20;
  undefined1 auStack_1c [4];
  undefined4 local_18;
  undefined1 auStack_14 [4];
  
  if (*param_1 == 0) {
    FUN_6010165c(0x28,DAT_60079dcc,0x27,DAT_60079dc8);
    bVar3 = false;
  }
  else {
    thunk_EXT_FUN_0000b4c2(DAT_60079dd0);
    FUN_60079bf4();
    local_20 = *param_1;
    FUN_600da478(auStack_1c,param_1 + 1);
    local_18 = *param_2;
    FUN_600da478(auStack_14,param_2 + 1);
    iVar2 = thunk_EXT_FUN_0000b532(0xa4);
    FUN_6007eb8c(iVar2,DAT_60079dd8,DAT_60079dd4,&local_20,&local_18);
    thunk_EXT_FUN_00001680(auStack_14);
    thunk_EXT_FUN_00001680(auStack_1c);
    *(undefined4 *)(iVar2 + 0x68) = DAT_60079ddc;
    cVar1 = FUN_6007e784(iVar2);
    bVar3 = cVar1 == '\0';
    if (bVar3) {
      FUN_60079c6c(DAT_60079de4,iVar2);
    }
    else {
      FUN_6010165c(0x28,DAT_60079dcc,0x3b,DAT_60079de0);
    }
    thunk_EXT_FUN_00007d10(DAT_60079dd0);
  }
  return bVar3;
}


