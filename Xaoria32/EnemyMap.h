// ��d�C���N���[�h�h�~
#ifndef __ENEMY_MAP_H__
#define __ENEMY_MAP_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EnemyMapData.h"	// �\����EnemyMapData
#include "Enemies.h"	// CEnemies
#include "SharedObject.h"	// CSharedObject
#include "BinaryFile.h"	// CBinaryFile

// �}�b�v�N���XCEnemyMap
class CEnemyMap : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		std::vector<EnemyMapData *> m_vecEnemyMapDataList;	// �G�l�~�[�}�b�v�f�[�^���X�g.
		CEnemies *m_pEnemies;	// �G�l�~�[�Y�I�u�W�F�N�g�|�C���^m_pEnemies.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CEnemyMap();	// �R���X�g���N�^CEnemyMap
		CEnemyMap(CScene *pScene);	// �R���X�g���N�^CEnemyMap(CScene *pScene)
		virtual ~CEnemyMap();	// �f�X�g���N�^~CEnemyMap

		// �����o�֐�
		int Create();	// �쐬����Create.
		int AddEnemy(int x, int y, int iWidth, int iHeight);	// �G�l�~�[�ǉ�.
		void AddEnemyAnimation(int iEnemyNo, RECT *lprcImgSrc, int nImgSrcID, RECT *lprcMaskSrc, int nMaskSrcID);	// �w��̃G�l�~�[�ɃA�j���[�V�����C���[�W��ǉ�.
		BOOL ExportFileEnemies(LPCTSTR lpctszFileName);	// �G�l�~�[�Y�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFileEnemies.
		BOOL ImportFileEnemies(LPCTSTR lpctszFileName);	// �G�l�~�[�Y�f�[�^���t�@�C������C���|�[�gImportFileEnemies.
		BOOL ImportResourceEnemies(int nID);	// �G�l�~�[�Y�f�[�^�����\�[�X�Ƃ��ăC���|�[�gImportResourceEnemies.
		BOOL ExportFileEnemyMapData(LPCTSTR lpctszFileName);	// �G�l�~�[�}�b�v�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFileEnemyMapData.
		BOOL ImportFileEnemyMapData(LPCTSTR lpctszFileName);	// �G�l�~�[�}�b�v�f�[�^���t�@�C������C���|�[�gImportFileEnemyMapData.
		BOOL ImportResourceEnemyMapData(int nID);	// �G�l�~�[�}�b�v�f�[�^�����\�[�X����C���|�[�gImportResourceEnemyMapData.
		void DeployEnemy(int x, int y, int iEnemyNo, int iState);	// �G�l�~�[�z�u.
		virtual int Proc();	// ����������Proc.
		virtual void Draw();	// �`�������Draw.
		void RemoveAll();	// �S�č폜.
		void Destroy();	// �j��Destroy.

};

#endif