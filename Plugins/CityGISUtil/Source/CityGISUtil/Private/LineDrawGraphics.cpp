#include "LineDrawGraphics.h"
#include "Components/LineBatchComponent.h"
#include "Engine/World.h"

TSoftObjectPtr<ULineBatchComponent> ULineDrawGraphics::GetDebugLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground)
{

	return (InWorld ? (bDepthIsForeground ? InWorld->ForegroundLineBatcher : ((bPersistentLines || (LifeTime > 0.f)) ? InWorld->PersistentLineBatcher : InWorld->LineBatcher)) : NULL);

}

TSoftObjectPtr<ULineBatchComponent> ULineDrawGraphics::BPDrawLine(UObject* context, FVector Start, FVector End, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent /*= false*/)
{
	UWorld* world = context->GetWorld();
	if (world)
	{
		TSoftObjectPtr<ULineBatchComponent> const LineBatcher = GetDebugLineBatcher(world, bPersistent, Duration, DepthPriority == SDPG_Foreground);
		float const ActualLifetime = bPersistent ? -1.0f : ((Duration > 0.f) ? Duration : LineBatcher->DefaultLifeTime);
		LineBatcher->DrawLine(Start, End, Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
		return LineBatcher;
	}
	return nullptr;
}

void ULineDrawGraphics::BPDrawBox(UObject* context, FVector Center, FVector Box, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent /*= false*/)
{

	UWorld* world = context->GetWorld();
	if (world)
	{

		TSoftObjectPtr<ULineBatchComponent> const LineBatcher = GetDebugLineBatcher(world, bPersistent, Duration, DepthPriority == SDPG_Foreground);
		float const ActualLifetime = bPersistent ? -1.0f : ((Duration > 0.f) ? Duration : LineBatcher->DefaultLifeTime);
		if (LineBatcher)
		{		LineBatcher->DrawLine(Center + FVector(Box.X, Box.Y, Box.Z), Center + FVector(Box.X, -Box.Y, Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(Box.X, -Box.Y, Box.Z), Center + FVector(-Box.X, -Box.Y, Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, -Box.Y, Box.Z), Center + FVector(-Box.X, Box.Y, Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, Box.Y, Box.Z), Center + FVector(Box.X, Box.Y, Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(Box.X, Box.Y, -Box.Z), Center + FVector(Box.X, -Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(Box.X, -Box.Y, -Box.Z), Center + FVector(-Box.X, -Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, -Box.Y, -Box.Z), Center + FVector(-Box.X, Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, Box.Y, -Box.Z), Center + FVector(Box.X, Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(Box.X, Box.Y, Box.Z), Center + FVector(Box.X, Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(Box.X, -Box.Y, Box.Z), Center + FVector(Box.X, -Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, -Box.Y, Box.Z), Center + FVector(-Box.X, -Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
			LineBatcher->DrawLine(Center + FVector(-Box.X, Box.Y, Box.Z), Center + FVector(-Box.X, Box.Y, -Box.Z), Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
		}
	}

}

void ULineDrawGraphics::BPDrawSoildBox(UObject* context, FVector Center, FVector Extent, FLinearColor Color, uint8 DepthPriority, float Duration, bool bPersistent/*=false*/)
{
	FBox Box = FBox::BuildAABB(Center, Extent);

	if (context)
	{
		UWorld* World = context->GetWorld();
		if (World)
		{
			
			TSoftObjectPtr<ULineBatchComponent> const LineBatcher = GetDebugLineBatcher(World, bPersistent, Duration, DepthPriority == SDPG_Foreground);
			if (LineBatcher != NULL)
			{

				float const ActualLifetime = bPersistent ? -1.0f : ((Duration > 0.f) ? Duration : LineBatcher->DefaultLifeTime);
				LineBatcher->DrawSolidBox(Box, FTransform::Identity, Color.ToFColor(true), DepthPriority, ActualLifetime);
			}
		}

	}
}

void ULineDrawGraphics::FlushLineComponent(TSoftObjectPtr<ULineBatchComponent> lines)
{
	lines->Flush();
	lines->DestroyComponent();
}

ALineDrawManager::ALineDrawManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TSoftObjectPtr<ULineBatchComponent> ALineDrawManager::GetDebugLineBatcher(const UWorld* InWorld, bool bPersistentLines, float LifeTime, bool bDepthIsForeground)
{
	return (InWorld ? (bDepthIsForeground ? InWorld->ForegroundLineBatcher : ((bPersistentLines || (LifeTime > 0.f)) ? InWorld->PersistentLineBatcher : InWorld->LineBatcher)) : NULL);
}

void ALineDrawManager::UpdateLineBatcher(UObject* context)
{
	UWorld* world = context->GetWorld();
	if (world)
	{
		TSoftObjectPtr<ULineBatchComponent> const LineBatcher = world->PersistentLineBatcher;
		LineBatcher->Flush();
		for (int i = 0; i < lineArray.Num(); i++)
		{
			const LineBatchInfo* line = &lineArray[i];
			LineBatcher->DrawLine(line->start, line->end, line->color.ToFColor(true), line->depthPriority, line->thickness, line->lifeTime);
		}

		for (int i = 0; i < meshArray.Num(); i++)
		{
			const MeshLineBatchInfo* mesh = &meshArray[i];
			LineBatcher->DrawMesh(mesh->Verts, mesh->Indices, mesh->color, mesh->depthPriority, mesh->lifeTime);
		}
	}
	
}

TSoftObjectPtr<ULineBatchComponent> ALineDrawManager::AddDrawLine(UObject* context, FVector Start, FVector End, FLinearColor Color, uint8 DepthPriority, float Thickness, float Duration, bool bPersistent)
{
	UWorld* world = context->GetWorld();
	if (world)
	{
		TSoftObjectPtr<ULineBatchComponent> const LineBatcher = GetDebugLineBatcher(world, bPersistent, Duration, DepthPriority == SDPG_Foreground);
		float const ActualLifetime = bPersistent ? -1.0f : ((Duration > 0.f) ? Duration : LineBatcher->DefaultLifeTime);
		LineBatcher->DrawLine(Start, End, Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime);
		lineArray.Add(LineBatchInfo(Start, End, Color.ToFColor(true), DepthPriority, Thickness, ActualLifetime));
		return LineBatcher;
	}
	return nullptr;
}

bool ALineDrawManager::RemoveDrawLine(UObject* context, int index)
{
	if (index >= lineArray.Num())
		return false;
	UWorld* world = context->GetWorld();
	if (world)
	{
		lineArray.RemoveAt(index);
		UpdateLineBatcher(context);
		return true;
	}
	return false;
}

bool ALineDrawManager::PopDrawLine(UObject* context)
{
	if (lineArray.Num() == 0)
		return false;
	UWorld* world = context->GetWorld();
	if (world)
	{
		lineArray.Pop();
		UpdateLineBatcher(context);
		return true;
	}
	return false;
}

void ALineDrawManager::StartMeasureArea()
{
	areaStartIndex = lineArray.Num();
}

bool ALineDrawManager::GenerateArea(UObject* context, FColor color, uint8 DepthPriority)
{
	//Delaunay cannot compile. 
	bool success = false;
	if (areaStartIndex != -1)
	{
		UWorld* world = context->GetWorld();
		
		if (world && areaStartIndex <= lineArray.Num() - 2)
		{
			int startId = areaStartIndex;
			int endId = lineArray.Num() - 1;
			int lineCount = endId - startId + 1;
			int vertexCount = lineCount + 1;
			
			// reset measure area flag
			areaStartIndex = -1;
			
			CDT::Triangulation<double> cdt(CDT::VertexInsertionOrder::AsProvided);
			struct CustomPoint2D
			{
				CustomPoint2D() { data[0] = 0; data[1] = 0; }
				CustomPoint2D(double x, double y) { data[0] = x; data[1] = y; }
				double data[2];
			};

			struct CustomEdge
			{
				CustomEdge() { vertices.first = 0; vertices.second = 1; }
				CustomEdge(std::size_t from, std::size_t to) { vertices.first = from; vertices.second = to; }
				std::pair<std::size_t, std::size_t> vertices;
			};
			std::vector<CustomPoint2D> vertices;
			vertices.resize(vertexCount);
			
			std::vector<CustomEdge> edges;
			edges.resize(vertexCount);

			for (int i = 0; i < lineCount; i++)
			{
				int curId = startId + i;
				vertices[i] = CustomPoint2D(lineArray[curId].start.X, lineArray[curId].start.Y);
				edges[i] = CustomEdge(i, i + 1);
			}
			vertices[vertexCount - 1] = CustomPoint2D(lineArray[startId + lineCount - 1].end.X, lineArray[startId + lineCount - 1].end.Y);
			edges[vertexCount - 1] = CustomEdge(lineCount, 0);
			cdt.insertVertices(
				vertices.begin(),
				vertices.end(),
				[](const CustomPoint2D& p) { return p.data[0]; },
				[](const CustomPoint2D& p) { return p.data[1]; }
			);

			cdt.conformToEdges(
				edges.begin(),
				edges.end(),
				[](const CustomEdge& e) { return e.vertices.first; },
				[](const CustomEdge& e) { return e.vertices.second; });
			//cdt.eraseSuperTriangle();

			cdt.eraseOuterTrianglesAndHoles();
			
			TArray<FVector> lineMeshVertices;
			TArray<int32> lineMeshIndices;
			lineMeshVertices.SetNum(cdt.vertices.size());
			lineMeshIndices.SetNum(cdt.triangles.size() * 3);

			for (int i = 0; i < lineMeshVertices.Num(); ++i)
			{
				CDT::V2d<double> v = cdt.vertices[i];
				lineMeshVertices[i] = FVector(v.x, v.y, 1);
			}

			for (int i = 0; i < cdt.triangles.size(); ++i)
			{
				CDT::Triangle id = cdt.triangles[i];
				for (int j = 0; j < id.vertices.size(); ++j)
				{
					lineMeshIndices[i*3+j] = id.vertices[j];
				}
			}

			meshArray.Add(MeshLineBatchInfo(lineMeshVertices, lineMeshIndices, color, 0));
			TSoftObjectPtr<ULineBatchComponent> const LineBatcher = world->PersistentLineBatcher;
			LineBatcher->DrawMesh(lineMeshVertices, lineMeshIndices, color, 0, -1);
		}
		
	}
	return success;
}

bool ALineDrawManager::RemoveDrawArea(UObject* context, int index)
{
	if (index >= meshArray.Num())
		return false;
	UWorld* world = context->GetWorld();
	if (world)
	{
		meshArray.RemoveAt(index);
		UpdateLineBatcher(context);
		return true;
	}
	return false;
}

bool ALineDrawManager::PopDrawArea(UObject* context)
{
	if (meshArray.Num() == 0)
		return false;
	UWorld* world = context->GetWorld();
	if (world)
	{
		meshArray.Pop();
		UpdateLineBatcher(context);
		return true;
	}
	return false;
}
